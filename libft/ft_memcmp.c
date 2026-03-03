/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:11:36 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/17 10:10:38 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "Hola";
	char	str2[] = "Hola";
	char	str3[] = "Mundo";

	if (ft_memcmp(str1, str2, sizeof(str1)) == 0)
		printf("str1 y str2 son iguales\n");
	else
		printf("str1 y str2 son diferentes\n");

	if (ft_memcmp(str1, str3, sizeof(str1)) == 0)
		printf("str1 y str3 son iguales\n");
	else
		printf("str1 y str3 son diferentes\n");

	return (0);
}*/