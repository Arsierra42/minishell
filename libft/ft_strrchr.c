/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:54:15 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/30 13:10:30 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}
/*
int main() {
	const char *str = "Hola Mundo";
	char c = 'o';

	char *result = ft_strrchr(str, c);
	if (result != NULL)
		printf("Última aparición de '%c': %s\n", c, result);
	else
		printf("Carácter '%c' no encontrado\n", c);

	return 0;
}*/