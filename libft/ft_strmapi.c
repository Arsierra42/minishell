/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 00:21:32 by marvin            #+#    #+#             */
/*   Updated: 2025/04/23 12:12:10 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned	int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/* 
char	my_func(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c - 32);
	else
		return (c);
}

int	main(void)
{
	const char	*original = "hola mundo!";
	char		*result;

	result = ft_strmapi(original, &my_func);
	if (!result)
	{
		printf("Error al aplicar ft_strmapi\n");
		return (1);
	}

	printf("Original: %s\n", original);
	printf("Modificado: %s\n", result);

	free(result);
	return (0);
}
 */