/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:15:39 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/17 10:10:33 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;	
	size_t			i;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == uc)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	// Un bloque de memoria (en este caso un array de caracteres)
	unsigned char data[] = "Hola, ¿cómo estás?";

	// Representación en UTF-8 de '¿' (0xC2 0xBF)
	unsigned char search[] = { 0xC2, 0xBF };  // Usamos un array de unsigned char

	// Llamamos ft_memchr pa encontrar el primer byte que coincida'¿'(0xC2, 0xBF)
	void *result = ft_memchr(data, search[0], sizeof(data));

	// Verificamos el resultado
	if (result != NULL)
	{
		// Si encontramos el carácter, mostramos la posición en la memoria
		printf("Carácter encontrado pos: %ld\n", (unsigned char *)result - data);
	}
	else
	{
		// Si no se encuentra, mostramos un mensaje indicando que no fue hallado
		printf("Carácter no encontrado.\n");
	}

	return 0;
}*/