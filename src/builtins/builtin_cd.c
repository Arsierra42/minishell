/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:14:18 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/08 13:09:19 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_perror(char *path)
{
	write(2, "minishell: cd: ", 15);
	if (path)
		write(2, path, ft_strlen(path));
	write(2, ": ", 2);
	perror(NULL);
	return (1);
}

static void	cd_update_pwd(t_shell *sh)
{
	char	cwd[PATH_MAX];
	char	*pwd;
	char	*oldpwd;

	oldpwd = env_get(sh->env, "PWD");
	if (oldpwd)
		env_set(&sh->env, "OLDPWD", oldpwd);
	pwd = getcwd(cwd, sizeof(cwd));
	if (pwd)
		env_set(&sh->env, "PWD", pwd);
}

static char	*get_cd_path(t_shell *sh, char *arg)
{
	char	*path;

	if (!arg)
		return (env_get(sh->env, "HOME"));
	if (ft_strcmp(arg, "-") == 0)
	{
		path = env_get(sh->env, "OLDPWD");
		if (!path)
			return (write(2, "minishell: cd: OLDPWD not set\n", 30), NULL);
		return (write(1, path, ft_strlen(path)), write(1, "\n", 1), path);
	}
	return (arg);
}

int	builtin_cd(t_shell *sh, char **argv)
{
	char	*path;

	if (argv && argv[1] && argv[2])
	{
		write(2, "minishell: cd: too many arguments\n", 34);
		return (1);
	}
	if (argv && argv[1])
		path = get_cd_path(sh, argv[1]);
	else
		path = get_cd_path(sh, NULL);
	if (!path)
	{
		if (!argv || !argv[1])
			write(2, "minishell: cd: HOME not set\n", 28);
		return (1);
	}
	if (chdir(path) == -1)
		return (cd_perror(path));
	cd_update_pwd(sh);
	return (0);
}
