/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_wait.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:47:14 by uelizegi          #+#    #+#             */
/*   Updated: 2026/01/27 11:53:17 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipeline_wait_to_status(int st)
{
	if (WIFEXITED(st))
		return (WEXITSTATUS(st));
	if (WIFSIGNALED(st))
		return (128 + WTERMSIG(st));
	return (1);
}

int	pipeline_wait_all(pid_t *pids, int count, pid_t last_pid)
{
	int	i;
	int	st;
	int	last_status;

	i = 0;
	last_status = 0;
	while (i < count)
	{
		while (waitpid(pids[i], &st, 0) == -1)
		{
			if (errno == EINTR)
				continue ;
			st = 1;
			break ;
		}
		if (pids[i] == last_pid)
			last_status = pipeline_wait_to_status(st);
		i++;
	}
	return (last_status);
}
