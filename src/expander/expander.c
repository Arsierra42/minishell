/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/08 13:03:35 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exp_strdup(const char *s);
char	*exp_append_char(char *dst, char c);
char	*exp_handle_dollar(t_shell *sh, const char *s, size_t *i, char *out);
char	*exp_expand_tilde(t_shell *sh, const char *s, size_t *i, char *out);

static int	is_quote_toggle(char c, int *in_squote, int *in_dquote)
{
	if (c == '\'' && !*in_dquote)
	{
		*in_squote = !*in_squote;
		return (1);
	}
	if (c == '"' && !*in_squote)
	{
		*in_dquote = !*in_dquote;
		return (1);
	}
	return (0);
}

static char	*append_plain(char *out, const char *s, size_t *i)
{
	out = exp_append_char(out, s[*i]);
	if (!out)
		return (NULL);
	(*i)++;
	return (out);
}

static char	*expand_loop(t_shell *sh, const char *s, char *out)
{
	size_t	i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (s[i])
	{
		if (is_quote_toggle(s[i], &sq, &dq))
			i++;
		else if (s[i] == '~' && !sq && !dq && (i == 0 || s[i - 1] == ' '))
			out = exp_expand_tilde(sh, s, &i, out);
		else if (s[i] == '$' && !sq)
			out = exp_handle_dollar(sh, s, &i, out);
		else
			out = append_plain(out, s, &i);
		if (!out)
			return (NULL);
	}
	return (out);
}

void	expand_tokens(t_shell *sh, t_token *tokens)
{
	char	*newv;

	while (tokens)
	{
		if (tokens->type == TOKEN_WORD && tokens->value)
		{
			newv = expand_word(sh, tokens->value);
			if (newv)
			{
				free(tokens->value);
				tokens->value = newv;
			}
		}
		tokens = tokens->next;
	}
}

char	*expand_word(t_shell *sh, const char *s)
{
	char	*out;

	if (!s)
		return (NULL);
	out = exp_strdup("");
	if (!out)
		return (NULL);
	out = expand_loop(sh, s, out);
	return (out);
}
