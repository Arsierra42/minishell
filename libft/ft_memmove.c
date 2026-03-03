/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:24:51 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/30 10:46:39 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dest);
}
/*
int main()
{
    char str[] = "Hola Mundo";  // Creamos una cadena de texto

    // Usamos memmove para mover los caracteres dentro de la misma cadena
	// Mover los primeros 5 caracteres después de la posición 5
    ft_memmove(str + 5, str, 5);
    // Imprimimos el resultado
    printf("Cadena después de ft_memmove: %s\n", str);

    return 0;
}*/