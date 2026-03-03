/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:44:02 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 13:35:40 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", ft_isprint('5'));
	printf("%d\n", ft_isprint('4'));

	return (0);
} */