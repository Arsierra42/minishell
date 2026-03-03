/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:19:10 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 13:24:17 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("ft_isalpha = %d\n", ft_isalpha('A'));
	printf("ft_isalpha = %d\n", ft_isalpha('z'));
	printf("ft_isalpha = %d\n", ft_isalpha('5'));
	printf("ft_isalpha = %d\n", ft_isalpha('@'));

	return (0);
} */