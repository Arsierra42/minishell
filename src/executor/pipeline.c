/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:12:39 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:30:38 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_setup_pipe(int prev_read, int pipefd[2], int has_next)
{
	if (prev_read != -1)
	{
		if (dup2(prev_read, STDIN_FILENO) == -1)
			exit(1);
		close(prev_read);
	}
	if (has_next)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit(1);
		close(pipefd[1]);
	}
}

static int	parent_update_prev(int prev_read, int pipefd[2], int has_next)
{
	if (prev_read != -1)
		close(prev_read);
	if (!has_next)
		return (-1);
	close(pipefd[1]);
	return (pipefd[0]);
}

static int	spawn_child(t_shell *sh, t_cmd *cur, int prev_read, int pipefd[2])
{
	pid_t	pid;
	int		has_next;

	has_next = (cur->next != NULL);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		child_setup_pipe(prev_read, pipefd, has_next);
		exec_pipeline_child(sh, cur);
	}
	return ((int)pid);
}

static int	pipeline_loop(t_shell *sh, t_cmd *cmds, pid_t *last_pid)
{
	pid_t	pids[1024];
	int		i;
	int		prev_read;
	int		pipefd[2];
	t_cmd	*cur;

	i = 0;
	prev_read = -1;
	cur = cmds;
	while (cur && i < 1024)
	{
		if (cur->next && pipe(pipefd) == -1)
			return (1);
		pids[i] = (pid_t)spawn_child(sh, cur, prev_read, pipefd);
		if (pids[i] == -1)
			return (1);
		*last_pid = pids[i];
		prev_read = parent_update_prev(prev_read, pipefd, (cur->next != NULL));
		cur = cur->next;
		i++;
	}
	if (prev_read != -1)
		close(prev_read);
	return (pipeline_wait_all(pids, i, *last_pid));
}

int	exec_pipeline(t_shell *sh, t_cmd *cmds)
{
	pid_t	last_pid;
	int		status;

	last_pid = -1;
	signals_exec_parent_handlers();
	status = pipeline_loop(sh, cmds, &last_pid);
	setup_signals_prompt();
	return (status);
}
