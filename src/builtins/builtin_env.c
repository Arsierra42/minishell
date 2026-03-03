/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:13:12 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:15:30 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_shell *sh, char **argv)
{
	t_env	*cur;

	if (!sh)
		return (1);
	if (argv && argv[1])
	{
		write(2, "minishell: env: ", 16);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": No such file or directory\n", 28);
		return (127);
	}
	cur = sh->env;
	while (cur)
	{
		if (cur->exported && cur->key && cur->value)
		{
			ft_putstr_fd(cur->key, 1);
			write(1, "=", 1);
			ft_putstr_fd(cur->value, 1);
			write(1, "\n", 1);
		}
		cur = cur->next;
	}
	return (0);
}
