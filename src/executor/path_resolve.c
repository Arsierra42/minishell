/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_resolve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:04:19 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/10 13:38:46 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_slash(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static char	*join_path_cmd(char *dir, char *cmd)
{
	char	*tmp;
	char	*out;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, cmd);
	free(tmp);
	return (out);
}

static char	*try_one_dir(char *dir, char *cmd)
{
	char	*candidate;

	if (!dir || dir[0] == '\0')
		dir = ".";
	candidate = join_path_cmd(dir, cmd);
	if (!candidate)
		return (NULL);
	if (access(candidate, F_OK) == 0)
		return (candidate);
	free(candidate);
	return (NULL);
}

static char	*search_in_path(char *cmd, char *path_value)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*dir;
	char	*found;

	i = 0;
	start = 0;
	len = ft_strlen(path_value);
	while (i <= len)
	{
		if (path_value[i] == ':' || path_value[i] == '\0')
		{
			dir = ft_substr(path_value, start, i - start);
			if (!dir)
				return (NULL);
			start = i + 1;
			found = try_one_dir(dir, cmd);
			free(dir);
			if (found)
				return (found);
		}
		i++;
	}
	return (NULL);
}

char	*resolve_cmd_path(t_shell *sh, char *cmd)
{
	char	*path_value;

	if (!cmd || !*cmd)
		return (NULL);
	if (has_slash(cmd))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path_value = env_get(sh->env, "PATH");
	if (!path_value)
		return (NULL);
	return (search_in_path(cmd, path_value));
}
