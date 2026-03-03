/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:37:48 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 13:22:29 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int	main(void)
{
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", ft_isascii('z'));
	printf("%d\n", ft_isascii('5'));
	printf("%d\n", ft_isascii(134));

	return (0);
} */