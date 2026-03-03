/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:07:14 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/30 08:57:37 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int main()
{
	char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

	printf("Contenido del arreglo antes de ft_bzero: \n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");

	// Llenamos los primeros 5 caracteres con 0
	ft_bzero(arr, 5);

	printf("Contenido del arreglo después de ft_bzero: \n");
	for (int i = 0; i < 10; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");

	return 0;
}*/