/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:38:29 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/23 09:38:36 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/* 
int	main(void)
{
	char	*result;

	// Caso 1: Espacios al principio y al final
	result = ft_strtrim("   Hola mundo   ", " ");
	printf("Caso 1 → [%s]\n", result);
	free(result);

	// Caso 2: Caracteres de tabulación y salto de línea
	result = ft_strtrim("\n\t  Hola mundo \t\n", " \n\t");
	printf("Caso 2 → [%s]\n", result);
	free(result);

	// Caso 3: Cadena vacía
	result = ft_strtrim("", " ");
	printf("Caso 3 → [%s]\n", result);
	free(result);

	// Caso 4: Cadena sin caracteres a recortar
	result = ft_strtrim("Hola", " ");
	printf("Caso 4 → [%s]\n", result);
	free(result);

	// Caso 5: Toda la cadena está hecha de caracteres a recortar
	result = ft_strtrim(" \n\t ", " \n\t");
	printf("Caso 5 → [%s]\n", result);
	free(result);

	// Caso 6: Set está vacío, no se recorta nada
	result = ft_strtrim("  Hola  ", "");
	printf("Caso 6 → [%s]\n", result);
	free(result);

	// Caso 7: s1 y set NULL
	result = ft_strtrim(NULL, " ");
	printf("Caso 7 → [%s]\n", result); // Debería devolver NULL

	result = ft_strtrim("Hola", NULL);
	printf("Caso 8 → [%s]\n", result); // Debería devolver NULL

	// Caso 9: Cadena sin caracteres a recortar
	result = ft_strtrim("Hola", "Ha");
	printf("Caso 9 → [%s]\n", result);
	free(result);

	return (0);
} */