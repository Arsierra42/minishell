/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:59:35 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:16:24 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_export_one(t_env *env)
{
	write(1, "declare -x ", 11);
	write(1, env->key, ft_strlen(env->key));
	if (env->value)
	{
		write(1, "=\"", 2);
		write(1, env->value, ft_strlen(env->value));
		write(1, "\"", 1);
	}
	write(1, "\n", 1);
}

static void	print_export(t_env *env)
{
	while (env)
	{
		if (env->exported)
			print_export_one(env);
		env = env->next;
	}
}

static int	export_key_only(t_shell *sh, char *arg)
{
	if (!is_valid_ident(arg))
		return (1);
	env_set(&sh->env, arg, NULL);
	return (0);
}

static int	export_key_value(t_shell *sh, char *arg, char *eq)
{
	char	*key;

	key = ft_substr(arg, 0, (size_t)(eq - arg));
	if (!key)
		return (1);
	if (!is_valid_ident(key))
	{
		free(key);
		return (1);
	}
	env_set(&sh->env, key, eq + 1);
	free(key);
	return (0);
}

int	builtin_export(t_shell *sh, char **argv)
{
	int		i;
	int		status;
	char	*eq;

	if (!argv[1])
	{
		print_export(sh->env);
		return (0);
	}
	i = 1;
	status = 0;
	while (argv[i])
	{
		eq = ft_strchr(argv[i], '=');
		if ((eq && export_key_value(sh, argv[i], eq))
			|| (!eq && export_key_only(sh, argv[i])))
		{
			write(2, "minishell: export: `", 20);
			write(2, argv[i], ft_strlen(argv[i]));
			write(2, "': not a valid identifier\n", 27);
			status = 1;
		}
		i++;
	}
	return (status);
}
