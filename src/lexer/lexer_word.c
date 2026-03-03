/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_is_space(char c);
int		lexer_is_op(char c);
char	*lexer_append_range(char *out, const char *s, size_t start, size_t len);

static int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

static int	update_quoted(int *quoted, char q)
{
	if (q == '\'')
		*quoted |= 1;
	if (q == '"')
		*quoted |= 2;
	return (1);
}

static char	*append_quoted(char *out, const char *s, size_t *i, int *quoted)
{
	size_t	start;
	char	q;

	q = s[*i];
	update_quoted(quoted, q);
	out = lexer_append_range(out, s, *i, 1);
	if (!out)
		return (NULL);
	(*i)++;
	start = *i;
	while (s[*i] && s[*i] != q)
		(*i)++;
	if (s[*i] != q)
		return (free(out), NULL);
	out = lexer_append_range(out, s, start, *i - start);
	if (!out)
		return (NULL);
	out = lexer_append_range(out, s, *i, 1);
	if (!out)
		return (NULL);
	(*i)++;
	return (out);
}

static char	*append_plain(char *out, const char *s, size_t *i)
{
	size_t	start;

	start = *i;
	while (s[*i] && !lexer_is_space(s[*i]) && !lexer_is_op(s[*i])
		&& !is_quote(s[*i]))
		(*i)++;
	out = lexer_append_range(out, s, start, *i - start);
	if (!out)
		return (NULL);
	return (out);
}

char	*lexer_read_word(const char *s, size_t *i, int *quoted)
{
	char	*out;

	out = NULL;
	*quoted = 0;
	while (s[*i] && !lexer_is_space(s[*i]) && !lexer_is_op(s[*i]))
	{
		if (is_quote(s[*i]))
			out = append_quoted(out, s, i, quoted);
		else
			out = append_plain(out, s, i);
		if (!out)
			return (NULL);
	}
	return (out);
}
