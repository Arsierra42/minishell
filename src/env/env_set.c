/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:35 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:18:09 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* si existe: reemplaza value si value != NULL (si es NULL, no pisa el valor)
marca exported = 1 siempre (porque export debe exportar)
si no existe: crea nodo (key dup, value dup o NULL) y exported=1 */

static int	env_add_fail(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
	return (1);
}

static void	env_add_back(t_env **env, t_env *node)
{
	t_env	*cur;

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

static int	env_add_new(t_env **env, char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (1);
	node->key = ft_strdup(key);
	node->value = NULL;
	if (value)
		node->value = ft_strdup(value);
	if (!node->key || (value && !node->value))
		return (env_add_fail(node));
	node->exported = 1;
	node->next = NULL;
	env_add_back(env, node);
	return (0);
}

void	env_set(t_env **env, char *key, char *value)
{
	t_env	*found;
	char	*newv;

	if (!env || !key || key[0] == '\0')
		return ;
	found = env_find(*env, key);
	if (!found)
	{
		env_add_new(env, key, value);
		return ;
	}
	found->exported = 1;
	if (!value)
		return ;
	newv = ft_strdup(value);
	if (!newv)
		return ;
	free(found->value);
	found->value = newv;
}
