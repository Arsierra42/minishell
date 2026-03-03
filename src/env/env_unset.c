/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:26:18 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:18:30 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_unset(t_env **env, char *key)
{
	t_env	*cur;
	t_env	*prev;

	if (!env || !*env || !key)
		return ;
	cur = *env;
	prev = NULL;
	while (cur)
	{
		if (cur->key && ft_strncmp(cur->key, key, ft_strlen(key) + 1) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*env = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
