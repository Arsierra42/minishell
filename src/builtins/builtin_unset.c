/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:53:49 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:17:23 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_shell *sh, char **argv)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	while (argv && argv[i])
	{
		if (!is_valid_ident(argv[i]))
		{
			write(2, "minishell: unset: `", 19);
			write(2, argv[i], ft_strlen(argv[i]));
			write(2, "': not a valid identifier\n", 27);
			status = 1;
		}
		else
			env_unset(&sh->env, argv[i]);
		i++;
	}
	return (status);
}
