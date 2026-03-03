/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:33:11 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_job	*parser_fail(t_job *jobs, t_cmd *job_cmds,
			char **argv, t_redir *redirs);
int		flush_job(t_job **jobs, t_job **last_job, t_cmd **job_cmds);
int		add_cmd_from_tokens(t_cmd **job_cmds, t_token **cur);
void	set_next_op(t_job *last_job, t_token_type type);

static t_job	*parse_loop(t_token *cur, t_job **jobs,
				t_job **last, t_cmd **cmds)
{
	while (cur)
	{
		if (cur->type == TOKEN_PIPE)
		{
			cur = cur->next;
			continue ;
		}
		if (cur->type == TOKEN_AND || cur->type == TOKEN_OR)
		{
			if (!flush_job(jobs, last, cmds))
				return (parser_fail(*jobs, NULL, NULL, NULL));
			set_next_op(*last, cur->type);
			cur = cur->next;
			continue ;
		}
		if (!add_cmd_from_tokens(cmds, &cur))
			return (parser_fail(*jobs, *cmds, NULL, NULL));
		if (cur && cur->type == TOKEN_PIPE)
			cur = cur->next;
	}
	return (*jobs);
}

t_job	*parser(t_token *tokens)
{
	t_job	*jobs;
	t_job	*last_job;
	t_cmd	*job_cmds;

	jobs = NULL;
	last_job = NULL;
	job_cmds = NULL;
	parse_loop(tokens, &jobs, &last_job, &job_cmds);
	if (!flush_job(&jobs, &last_job, &job_cmds))
		return (parser_fail(jobs, NULL, NULL, NULL));
	return (jobs);
}
