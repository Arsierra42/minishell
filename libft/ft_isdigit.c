/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:34:03 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 13:25:57 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isdigit('z'));
	printf("%d\n", ft_isdigit('5'));
	printf("%d\n", ft_isdigit('4'));

	return (0);
} */