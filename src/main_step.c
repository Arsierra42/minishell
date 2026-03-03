/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:40:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 13:40:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_only_spaces(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int	handle_no_tokens(t_shell *sh, char *line)
{
	sh->last_status = 2;
	(void)line;
	return (2);
}

static int	handle_no_jobs(t_shell *sh, t_token *tokens)
{
	free_tokens(tokens);
	sh->last_status = 2;
	return (2);
}

int	minishell_step(t_shell *sh, char *line)
{
	t_token	*tokens;
	t_job	*jobs;

	if (is_only_spaces(line))
		return (sh->last_status);
	add_history(line);
	tokens = lexer(line);
	if (!tokens)
		return (handle_no_tokens(sh, line));
	expand_tokens(sh, tokens);
	jobs = parser(tokens);
	if (!jobs)
		return (handle_no_jobs(sh, tokens));
	free_tokens(tokens);
	sh->last_status = execute(sh, jobs);
	free_jobs(jobs);
	return (sh->last_status);
}
