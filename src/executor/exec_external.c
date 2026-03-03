/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:41:12 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:21:39 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	wait_child(pid_t pid, int *st)
{
	while (waitpid(pid, st, 0) == -1)
	{
		if (errno == EINTR)
			continue ;
		return (-1);
	}
	return (0);
}

static int	wait_to_status(int st)
{
	if (WIFEXITED(st))
		return (WEXITSTATUS(st));
	if (WIFSIGNALED(st))
		return (128 + WTERMSIG(st));
	return (1);
}

static void	child_exec_external(t_shell *sh, t_cmd *cmd, char **envp)
{
	char	*path;

	setup_signals_exec();
	if (apply_redirs(cmd->redirs))
	{
		free_str_array_null(envp);
		exit(1);
	}
	path = resolve_cmd_path(sh, cmd->argv[0]);
	if (!path)
	{
		write(2, "minishell: ", 11);
		write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
		write(2, ": command not found\n", 20);
		free_str_array_null(envp);
		exit(127);
	}
	execve(path, cmd->argv, envp);
	perror(path);
	free(path);
	free_str_array_null(envp);
	if (errno == ENOENT)
		exit(127);
	exit(126);
}

static int	parent_wait_external(pid_t pid)
{
	int	st;

	signals_exec_parent_handlers();
	if (wait_child(pid, &st) == -1)
	{
		setup_signals_prompt();
		return (1);
	}
	setup_signals_prompt();
	return (wait_to_status(st));
}

int	exec_external_one(t_shell *sh, t_cmd *cmd)
{
	pid_t	pid;
	char	**envp;

	envp = env_to_array(sh->env);
	if (!envp)
		return (1);
	pid = fork();
	if (pid == -1)
	{
		free_str_array_null(envp);
		return (1);
	}
	if (pid == 0)
		child_exec_external(sh, cmd, envp);
	free_str_array_null(envp);
	return (parent_wait_external(pid));
}
