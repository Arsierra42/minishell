/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:20:47 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/23 12:42:41 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

/* int	main(void)
{
	// Caso 1: Reserva normal
	int *arr = (int *)ft_calloc(5, sizeof(int));
	if (!arr)
		return (printf("Error: ft_calloc devolvió NULL\n"), 1);
	for (int i = 0; i < 5; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
	free(arr);

	// Caso 2: nmemb = 0, size = 0
	void *zero = ft_calloc(0, 0);
	if (zero == NULL)
		printf("Caso 2: ft_calloc(0, 0) retornó NULL (válido)\n");
	else
	{
		printf("Caso 2: ft_calloc(0, 0) retornó no NULL (tambien aceptado)\n");
		free(zero);
	}

	// Caso 3: Multiplicación que da overflow (puede fallar si no se maneja)
	size_t huge = (size_t)-1;
	void *overflow = ft_calloc(huge, 2); // muy grande
	if (!overflow)
		printf("Caso 3: ft_calloc números grandes devolvió NULL (correcto)\n");
	else
	{
		printf("Caso 3: ft_calloc devolvió memoria ¡esto podría ser error!\n");
		free(overflow);
	}

	// Caso 4: Comparación con calloc original
	char *original = (char *)calloc(10, sizeof(char));
	char *custom = (char *)ft_calloc(10, sizeof(char));
	if (original && custom && memcmp(original, custom, 10) == 0)
		printf("Caso 4: ft_calloc y calloc se comportan igual\n");
	else
		printf("Caso 4: Los comportamientos no coinciden\n");
	free(original);
	free(custom);

	return 0;
} */