/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:45:33 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 13:24:06 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('z'));
	printf("%d\n", ft_isalnum('5'));
	printf("%d\n", ft_isalnum('['));

	return (0);
} */