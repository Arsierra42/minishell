/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exp_expand_env(t_shell *sh, const char *s, size_t *i, char *out);

char	*exp_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*out;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*exp_append_char(char *dst, char c)
{
	size_t	len;
	char	*out;
	size_t	i;

	if (!dst)
		return (NULL);
	len = ft_strlen(dst);
	out = (char *)malloc(len + 2);
	if (!out)
		return (free(dst), NULL);
	i = 0;
	while (i < len)
	{
		out[i] = dst[i];
		i++;
	}
	out[len] = c;
	out[len + 1] = '\0';
	free(dst);
	return (out);
}

char	*exp_append_str(char *out, char *s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		out = exp_append_char(out, s[j]);
		if (!out)
			return (NULL);
		j++;
	}
	return (out);
}

char	*exp_expand_status(t_shell *sh, size_t *i, char *out)
{
	char	*status;

	status = ft_itoa(sh->last_status);
	if (!status)
		return (out);
	out = exp_append_str(out, status);
	free(status);
	(*i)++;
	return (out);
}

char	*exp_handle_dollar(t_shell *sh, const char *s, size_t *i, char *out)
{
	(*i)++;
	if (s[*i] == '?')
		return (exp_expand_status(sh, i, out));
	return (exp_expand_env(sh, s, i, out));
}
