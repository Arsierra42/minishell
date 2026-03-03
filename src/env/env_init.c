/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:18:48 by uelizegi          #+#    #+#             */
/*   Updated: 2026/01/30 13:26:05 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Crea nodos de la lista de entorno de forma limpia */
static t_env	*env_new(char *key, char *value)
{
	t_env	*n;

	n = malloc(sizeof(t_env));
	if (!n)
		return (NULL);
	n->key = key;
	n->value = value;
	n->exported = 1;
	n->next = NULL;
	return (n);
}

/* Mantiene la lista en el mismo orden que envp
Añade node al final de la lista enlazada *env
Si la lista está vacía (*env == NULL), el nuevo nodo pasa a ser el primero.
Si no, recorre hasta el último y hace last->next = node. */
static void	env_add_back(t_env **env, t_env *node)
{
	t_env	*cur;

	if (!env || !node)
		return ;
	if (!*env)
	{
		*env = node;
		return ;
	}
	cur = *env;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
}

/* Es un “parseador de una línea” (KEY=VALUE) y un “insertador” */
static int	env_make_kv(char *entry, char **key, char **value)
{
	char	*eq;

	*key = NULL;
	*value = NULL;
	if (!entry)
		return (0);
	eq = ft_strchr(entry, '=');
	if (!eq)
		return (0);
	*key = ft_substr(entry, 0, (size_t)(eq - entry));
	*value = ft_strdup(eq + 1);
	if (!*key || !*value)
	{
		free(*key);
		free(*value);
		*key = NULL;
		*value = NULL;
		return (-1);
	}
	return (1);
}

static int	env_push_kv(t_env **env, char *entry)
{
	char	*key;
	char	*value;
	t_env	*node;
	int		r;

	r = env_make_kv(entry, &key, &value);
	if (r == 0)
		return (1);
	if (r == -1)
		return (0);
	node = env_new(key, value);
	if (!node)
	{
		free(key);
		free(value);
		return (0);
	}
	env_add_back(env, node);
	return (1);
}

/* Inicializa sh.env al arrancar tu minishell */
t_env	*env_init(char **envp)
{
	t_env	*env;
	int		i;

	env = NULL;
	i = 0;
	while (envp && envp[i])
	{
		if (!env_push_kv(&env, envp[i]))
		{
			env_free(env);
			return (NULL);
		}
		i++;
	}
	return (env);
}
