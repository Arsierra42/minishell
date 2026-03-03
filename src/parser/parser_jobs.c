/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_back(t_cmd **list, t_cmd *new);
void	job_add_back(t_job **list, t_job *new);
t_job	*job_new(t_cmd *cmds);

t_job	*parser_fail(t_job *jobs, t_cmd *job_cmds, char **argv, t_redir *redirs)
{
	if (argv)
		free_str_array_null(argv);
	if (redirs)
		free_redirs(redirs);
	if (job_cmds)
		free_cmds(job_cmds);
	if (jobs)
		free_jobs(jobs);
	return (NULL);
}

int	flush_job(t_job **jobs, t_job **last_job, t_cmd **job_cmds)
{
	t_job	*j;

	if (!*job_cmds)
		return (1);
	j = job_new(*job_cmds);
	if (!j)
		return (0);
	job_add_back(jobs, j);
	*last_job = j;
	*job_cmds = NULL;
	return (1);
}

int	add_cmd_from_tokens(t_cmd **job_cmds, t_token **cur)
{
	char	**argv;
	t_cmd	*cmd;
	t_redir	*redirs;

	redirs = NULL;
	argv = dup_argv_from_tokens(cur, &redirs);
	if (!argv)
		return (free_redirs(redirs), 0);
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (free_str_array_null(argv), free_redirs(redirs), 0);
	cmd->argv = argv;
	cmd->redirs = redirs;
	cmd->next = NULL;
	cmd_add_back(job_cmds, cmd);
	return (1);
}
