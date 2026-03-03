/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*lexer_substr_dup(const char *s, size_t start, size_t len);

static size_t	slen(char *s)
{
	if (!s)
		return (0);
	return (ft_strlen(s));
}

static void	copy_into(char *dst, char *src, size_t offset)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dst[offset + i] = src[i];
		i++;
	}
}

static char	*join_free(char *a, char *b)
{
	char	*out;
	size_t	la;
	size_t	lb;

	la = slen(a);
	lb = slen(b);
	out = (char *)malloc(la + lb + 1);
	if (!out)
		return (free(a), free(b), NULL);
	copy_into(out, a, 0);
	copy_into(out, b, la);
	out[la + lb] = '\0';
	return (free(a), free(b), out);
}

char	*lexer_append_range(char *out, const char *s, size_t start, size_t len)
{
	char	*part;

	part = lexer_substr_dup(s, start, len);
	if (!part)
		return (free(out), NULL);
	return (join_free(out, part));
}
