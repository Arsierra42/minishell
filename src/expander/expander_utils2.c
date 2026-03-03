/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exp_append_char(char *dst, char c);
char	*exp_append_str(char *out, char *s);

char	*exp_expand_env(t_shell *sh, const char *s, size_t *i, char *out)
{
	size_t	start;
	char	*key;
	char	*val;

	start = *i;
	while (s[*i] && (ft_isalnum(s[*i]) || s[*i] == '_'))
		(*i)++;
	if (*i == start)
		return (exp_append_char(out, '$'));
	key = ft_substr(s, start, *i - start);
	if (!key)
		return (out);
	val = env_get(sh->env, key);
	free(key);
	if (!val)
		return (out);
	return (exp_append_str(out, val));
}
