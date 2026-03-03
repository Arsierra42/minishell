/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:02:55 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:18:26 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* recorre la lista enlazada t_env y 
cuenta cuántos nodos tienen env->exported == 1
cuántas variables deben ir al char **envp que pasarás a execve */
static int	env_count_exported(t_env *env)
{
	int	count;

	count = 0;
	while (env)
	{
		if (env->exported && env->key && env->value)
			count++;
		env = env->next;
	}
	return (count);
}

/* construye un string nuevo con formato
execve no acepta tu lista t_env; necesita un 
char ** donde cada string sea "KEY=VALUE". */
static char	*env_join_kv(char *key, char *value)
{
	char	*tmp;
	char	*out;

	if (!key)
		return (NULL);
	if (!value)
		value = "";
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	out = ft_strjoin(tmp, value);
	free(tmp);
	return (out);
}

/* libera parcialmente un array de strings arr */
static void	free_str_array(char **arr, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/* convierte toda la lista t_env en un char ** estilo envp
También te sirve si algún builtin necesita trabajar con un char ** */
char	**env_to_array(t_env *env)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (env_count_exported(env) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (env)
	{
		if (env->exported && env->key && env->value)
		{
			arr[i] = env_join_kv(env->key, env->value);
			if (!arr[i])
			{
				free_str_array(arr, i);
				return (NULL);
			}
			i++;
		}
		env = env->next;
	}
	arr[i] = NULL;
	return (arr);
}
