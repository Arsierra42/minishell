/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:08:47 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:17:21 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_shell *sh, t_cmd *cmd)
{
	char	**argv;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return (1);
	argv = cmd->argv;
	if (ft_strcmp(argv[0], "echo") == 0)
		return (builtin_echo(argv));
	if (ft_strcmp(argv[0], "pwd") == 0)
		return (builtin_pwd());
	if (ft_strcmp(argv[0], "env") == 0)
		return (builtin_env(sh, argv));
	if (ft_strcmp(argv[0], "exit") == 0)
		return (builtin_exit(sh, argv));
	if (ft_strcmp(argv[0], "cd") == 0)
		return (builtin_cd(sh, argv));
	if (ft_strcmp(argv[0], "export") == 0)
		return (builtin_export(sh, argv));
	if (ft_strcmp(argv[0], "unset") == 0)
		return (builtin_unset(sh, argv));
	return (1);
}
