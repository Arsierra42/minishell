/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:36:43 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/23 09:38:12 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/* 
int main(void)
{
	// Ejemplo 1: Subcadena normal
	char	*str1 = "Hello, World!";
	char	*substr1 = ft_substr(str1, 7, 5);  // Debe devolver "World"
	if (substr1 != NULL) {
		printf("Subcadena 1: %s\n", substr1);
		free(substr1);  // Liberamos la memoria
	} else {
		printf("Error en la creación de la subcadena 1\n");
	}

	// Ejemplo 2: Caso en el que 'start' es mayor que la longitud de la cadena
	char	*str2 = "Short";
	char	*substr2 = ft_substr(str2, 10, 5);  // Debe devolver ""
	if (substr2 != NULL) {
		printf("Subcadena 2: %s\n", substr2);
		free(substr2);  // Liberamos la memoria
	} else {
		printf("Error en la creación de la subcadena 2\n");
	}

	// Ejemplo 3: La longitud es mayor que lo que queda a partir del 'start'
	char	*str3 = "123456789";
	char	*substr3 = ft_substr(str3, 5, 10);  // Debe devolver "6789"
	if (substr3 != NULL) {
		printf("Subcadena 3: %s\n", substr3);
		free(substr3);  // Liberamos la memoria
	} else {
		printf("Error en la creación de la subcadena 3\n");
	}
	return (0);
} */