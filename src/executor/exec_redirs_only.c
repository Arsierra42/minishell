/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirs_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:22:18 by uelizegi          #+#    #+#             */
/*   Updated: 2026/01/15 14:22:32 by uelizegi         ###   ########.fr       */
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

int	exec_redirs_only(t_cmd *cmd)
{
	int	in_save;
	int	out_save;
	int	status;

	in_save = -1;
	out_save = -1;
	if (!cmd || !cmd->redirs)
		return (0);
	if (save_stdio(&in_save, &out_save))
		return (1);
	status = apply_redirs(cmd->redirs);
	restore_stdio(in_save, out_save);
	if (status)
		return (1);
	return (0);
}
