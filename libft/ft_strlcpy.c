/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:27:12 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/30 11:19:14 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/* 
int	main(void)
{
	char	dst[6];  // Un tamaño pequeño para probar el límite
	const char	*src = "Hola Mundo!";
	size_t	len;

	// Copiar de src a dst con un tamaño limitado de 6 (5 caracteres + \0)
	len = ft_strlcpy(dst, src, sizeof(dst));

	printf("Destino: \"%s\"\n", dst);
	printf("Longitud devuelta: %zu\n", len);

	return (0);
} */