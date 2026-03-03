/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:59:55 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/25 11:14:09 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, len + 1);
	return (dup);
}
/* 
int	main(void)
{
	const char	*original = "Hola 42!";
	const char	*vacia = "";
	char		*dup1;
	char		*dup2;

	// Probar cadena normal
	dup1 = ft_strdup(original);
	dup2 = strdup(original);

	printf("Original     : %s\n", original);
	printf("ft_strdup    : %s\n", dup1);
	printf("strdup       : %s\n", dup2);

	free(dup1);
	free(dup2);

	// Probar cadena vacía
	dup1 = ft_strdup(vacia);
	dup2 = strdup(vacia);

	printf("\nCadena vacía:\n");
	printf("ft_strdup    : \"%s\"\n", dup1);
	printf("strdup       : \"%s\"\n", dup2);

	free(dup1);
	free(dup2);

	return (0);
} */