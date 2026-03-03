/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:14:21 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	should_run_next(t_op op, int last_status)
{
	if (op == OP_AND)
		return (last_status == 0);
	if (op == OP_OR)
		return (last_status != 0);
	return (1);
}

static int	run_cmds(t_shell *sh, t_cmd *cmds)
{
	int	status;

	if (!cmds)
		return (0);
	if (sh && sh->should_exit)
		return (sh->exit_code);
	if (prepare_heredocs(cmds))
		return (1);
	if (cmds->next)
		status = exec_pipeline(sh, cmds);
	else if (!cmds->argv || !cmds->argv[0])
		status = exec_redirs_only(cmds);
	else
		status = exec_cmd_simple(sh, cmds);
	return (status);
}

int	execute(t_shell *sh, t_job *jobs)
{
	int		status;
	t_job	*cur;
	t_op	op;

	if (!sh)
		return (1);
	status = 0;
	cur = jobs;
	while (cur)
	{
		if (status == 0)
			op = OP_NONE;
		else
			op = cur->next_op;
		if (should_run_next(op, status))
			status = run_cmds(sh, cur->cmds);
		sh->last_status = status;
		if (sh->should_exit)
			break ;
		cur = cur->next;
	}
	return (status);
}
