/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:27:19 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/24 13:04:47 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/* int	main(void)
{
	// Algunos ejemplos con distintos tipos de entrada
	const char *ej1 = "   12a3";
	const char *ej2 = "   -456";
	const char *ej3 = "+789";
	const char *ej4 = "42abc";
	const char *ej5 = "abc42";
	const char *ej6 = "   \t\n 1000";
	const char *ej7 = "-2147483648";
	const char *ej8 = "-2147483649";

	// Probamos cada uno y explicamos
	printf("Entrada: \"%s\" → Resultado: %d\n", ej1, ft_atoi(ej1));  // 123
	printf("Entrada: \"%s\" → Resultado: %d\n", ej2, ft_atoi(ej2));  // -456
	printf("Entrada: \"%s\" → Resultado: %d\n", ej3, ft_atoi(ej3));  // 789
	printf("Entrada: \"%s\" → Resultado: %d\n", ej4, ft_atoi(ej4));  // 42 \
	(se detiene cuando llega a la 'a')
	printf("Entrada: \"%s\" → Resultado: %d\n", ej5, ft_atoi(ej5));  // 0 \
	(empieza con una letra no hay conversion)
	printf("Entrada: \"%s\" → Resultado: %d\n", ej6, ft_atoi(ej6));  // 1000
	printf("Entrada: \"%s\" → Resultado: %d\n", ej7, ft_atoi(ej7));
	printf("Entrada: \"%s\" → Resultado: %d\n", ej8, ft_atoi(ej8));

	// Probamos cada uno y explicamos
	printf("Entrada: \"%s\" → Resultado: %d\n", ej1, atoi(ej1));  // 123
	printf("Entrada: \"%s\" → Resultado: %d\n", ej2, atoi(ej2));  // -456
	printf("Entrada: \"%s\" → Resultado: %d\n", ej3, atoi(ej3));  // 789
	printf("Entrada: \"%s\" → Resultado: %d\n", ej4, atoi(ej4));  // 42 \
	(se detiene cuando llega a la 'a')
	printf("Entrada: \"%s\" → Resultado: %d\n", ej5, atoi(ej5));  // 0 \
	(empieza con una letra no hay conversion)
	printf("Entrada: \"%s\" → Resultado: %d\n", ej6, atoi(ej6));  // 1000
	printf("Entrada: \"%s\" → Resultado: %d\n", ej7, atoi(ej7));
	printf("Entrada: \"%s\" → Resultado: %d\n", ej8, atoi(ej8));
	return (0);
} */