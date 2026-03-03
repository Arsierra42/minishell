/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:52:39 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/30 14:11:57 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/* 	
int	main(void)
{
	const char	*text = "Hola mundo, esto es una prueba";
	const char	*search1 = "mundo";
	const char	*search2 = "prueba";
	const char	*search3 = "";
	const char	*search4 = "noexiste";

	char	*result;

	// Caso 1: palabra que sí está dentro del texto
	result = ft_strnstr(text, search1, 20);
	printf("Buscar '%s' en '%s' (hasta 20): %s\n", search1, text, result ? \
	result : "No encontrado");

	// Caso 2: palabra al final del texto
	result = ft_strnstr(text, search2, 40);
	printf("Buscar '%s' en '%s' (hasta 40): %s\n", search2, text, result ?\
	 result : "No encontrado");

	// Caso 3: cadena vacía (needle vacío)
	result = ft_strnstr(text, search3, 10);
	printf("Buscar cadena vacía en '%s': %s\n", text, result ? \
	result : "No encontrado");

	// Caso 4: palabra que no existe
	result = ft_strnstr(text, search4, 30);
	printf("Buscar '%s' en '%s': %s\n", search4, text, result ?\
	 result : "No encontrado");

	// Caso 5: palabra sí existe pero fuera del rango len
	result = ft_strnstr(text, search2, 10);
	printf("Buscar '%s' en '%s' (hasta 10): %s\n", search2, text, result ?\
	 result : "No encontrado");

	return (0);
} */