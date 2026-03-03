/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:19:22 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/10 13:52:03 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric_str(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	to_exit_code(const char *s)
{
	long	n;

	n = ft_atol(s);
	n %= 256;
	if (n < 0)
		n += 256;
	return ((int)n);
}

static int	exit_numeric_required(t_shell *sh, const char *arg)
{
	write(2, "minishell: exit: ", 17);
	write(2, arg, ft_strlen(arg));
	write(2, ": numeric argument required\n", 29);
	sh->should_exit = 1;
	sh->exit_code = 2;
	return (2);
}

static int	exit_too_many_args(t_shell *sh)
{
	write(2, "minishell: exit: too many arguments\n", 36);
	sh->last_status = 1;
	return (1);
}

int	builtin_exit(t_shell *sh, char **argv)
{
	int	code;

	if (!sh)
		return (1);
	if (!argv || !argv[1])
	{
		sh->should_exit = 1;
		sh->exit_code = sh->last_status;
		return (sh->exit_code);
	}
	if (!is_numeric_str(argv[1]))
		return (exit_numeric_required(sh, argv[1]));
	if (argv[2])
		return (exit_too_many_args(sh));
	code = to_exit_code(argv[1]);
	sh->should_exit = 1;
	sh->exit_code = code;
	return (code);
}
