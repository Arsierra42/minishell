/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:15:32 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/10 14:15:55 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	save_stdio(int *in_save, int *out_save)
{
	*in_save = dup(STDIN_FILENO);
	*out_save = dup(STDOUT_FILENO);
	if (*in_save == -1 || *out_save == -1)
	{
		perror("dup");
		if (*in_save != -1)
			close(*in_save);
		if (*out_save != -1)
			close(*out_save);
		return (1);
	}
	return (0);
}

static void	restore_stdio(int in_save, int out_save)
{
	if (in_save != -1)
	{
		dup2(in_save, STDIN_FILENO);
		close(in_save);
	}
	if (out_save != -1)
	{
		dup2(out_save, STDOUT_FILENO);
		close(out_save);
	}
}

static int	exec_builtin_in_parent(t_shell *sh, t_cmd *cmd)
{
	int	in_save;
	int	out_save;
	int	status;

	in_save = -1;
	out_save = -1;
	if (save_stdio(&in_save, &out_save))
		return (1);
	if (apply_redirs(cmd->redirs))
	{
		restore_stdio(in_save, out_save);
		return (1);
	}
	status = exec_builtin(sh, cmd);
	restore_stdio(in_save, out_save);
	return (status);
}

int	exec_cmd_simple(t_shell *sh, t_cmd *cmd)
{
	int	i;
	int	j;

	if (!sh || !cmd || !cmd->argv || !cmd->argv[0])
		return (0);
	j = 0;
	i = 0;
	while (cmd->argv[i])
	{
		if (cmd->argv[i][0] != '\0')
		{
			cmd->argv[j] = cmd->argv[i];
			j++;
		}
		i++;
	}
	cmd->argv[j] = NULL;
	if (!cmd->argv[0])
		return (0);
	if (is_builtin(cmd->argv[0]))
		return (exec_builtin_in_parent(sh, cmd));
	return (exec_external_one(sh, cmd));
}
