/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:09:57 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/08 10:57:13 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(t_token *t)
{
	int	count;

	count = 0;
	while (t && t->type != TOKEN_PIPE
		&& t->type != TOKEN_AND && t->type != TOKEN_OR)
	{
		if (is_redir_token(t->type))
		{
			t = t->next;
			if (t && t->type == TOKEN_WORD)
				t = t->next;
			continue ;
		}
		if (t->type == TOKEN_WORD)
			count++;
		t = t->next;
	}
	return (count);
}

static void	free_argv(char **argv, int i)
{
	while (i > 0)
		free(argv[--i]);
	free(argv);
}

static int	add_word(char **argv, int *i, t_token *cur)
{
	argv[*i] = ft_strdup(cur->value);
	if (!argv[*i])
		return (0);
	(*i)++;
	return (1);
}

static int	process_token(t_token **cur, t_redir **redirs, char **argv, int *i)
{
	if (is_redir_token((*cur)->type))
	{
		if (!handle_redir(cur, redirs))
			return (0);
	}
	else if (*cur && (*cur)->type == TOKEN_WORD)
	{
		if (!add_word(argv, i, *cur))
			return (0);
		*cur = (*cur)->next;
	}
	else if (*cur)
		*cur = (*cur)->next;
	return (1);
}

char	**dup_argv_from_tokens(t_token **cur, t_redir **redirs)
{
	int		n;
	char	**argv;
	int		i;

	n = count_words(*cur);
	argv = (char **)malloc(sizeof(char *) * (n + 1));
	if (!argv)
		return (NULL);
	i = 0;
	while (*cur && (*cur)->type != TOKEN_PIPE
		&& (*cur)->type != TOKEN_AND && (*cur)->type != TOKEN_OR)
	{
		if (!process_token(cur, redirs, argv, &i))
			return (free_argv(argv, i), NULL);
	}
	argv[i] = NULL;
	return (argv);
}
