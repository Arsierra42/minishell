/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:43:04 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 12:26:33 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_not_found(char *cmd, char **envp)
{
	write(2, "minishell: ", 11);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	free_str_array_null(envp);
	exit(127);
}

static void	child_execve_fail(char *path, char **envp)
{
	perror(path);
	free(path);
	free_str_array_null(envp);
	if (errno == ENOENT)
		exit(127);
	exit(126);
}

static void	child_exec_external(t_shell *sh, t_cmd *cmd)
{
	char	**envp;
	char	*path;

	envp = env_to_array(sh->env);
	if (!envp)
		exit(1);
	path = resolve_cmd_path(sh, cmd->argv[0]);
	if (!path)
		child_not_found(cmd->argv[0], envp);
	execve(path, cmd->argv, envp);
	child_execve_fail(path, envp);
}

static void	child_exec_after_redirs(t_shell *sh, t_cmd *cmd)
{
	if (!cmd->argv || !cmd->argv[0])
		exit(0);
	if (is_builtin(cmd->argv[0]))
		exit(exec_builtin(sh, cmd));
	child_exec_external(sh, cmd);
}

void	exec_pipeline_child(t_shell *sh, t_cmd *cmd)
{
	setup_signals_exec();
	if (apply_redirs(cmd->redirs))
		exit(1);
	child_exec_after_redirs(sh, cmd);
}
