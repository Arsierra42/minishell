/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:03:54 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/17 10:10:54 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
// Función main para probar ft_memset
int main()
{
    // Creamos un arreglo de 10 caracteres
    char arr[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    
    // Llenamos los primeros 5 elementos del arreglo con el valor 'A' (ASCII 65)
    ft_memset(arr, 'P', 7);

    // Imprimimos el contenido del arreglo para verificar el resultado
    printf("Contenido del arreglo después de ft_memset: \n");
    for (int i = 0; i < 10; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");

    return 0;
}*/
