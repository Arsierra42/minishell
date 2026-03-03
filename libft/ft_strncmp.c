/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:26:54 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/17 10:11:39 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
	const char *tests[][2] = {
		{"hola", "hola"},
		{"hola", "hol"},
		{"hol", "hola"},
		{"abc", "abcdef"},
		{"abcdef", "abc"},
		{"", "abc"},
		{"abc", ""},
		{"abc", "abd"},
		{"abc", "abc"},
		{"abc", "abC"}
	};

	size_t n_values[] = {2, 3, 4, 5, 6};
	size_t i, j;

	for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
	{
		for (j = 0; j < sizeof(n_values) / sizeof(n_values[0]); j++)
		{
			int result = ft_strncmp(tests[i][0], tests[i][1], n_values[j]);
			printf("ft_strncmp(\"%s\", \"%s\", %zu) = %d\n",
				tests[i][0], tests[i][1], n_values[j], result);
		}
		printf("------------\n");
	}

	return 0;
}*/