/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tilde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:58:22 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/08 13:06:13 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exp_append_char(char *dst, char c);

char	*exp_expand_tilde(t_shell *sh, const char *s, size_t *i, char *out)
{
	char	*home;
	size_t	j;

	(void)s;
	(*i)++;
	home = env_get(sh->env, "HOME");
	if (!home)
		return (out);
	j = 0;
	while (home[j])
	{
		out = exp_append_char(out, home[j]);
		if (!out)
			return (NULL);
		j++;
	}
	return (out);
}
