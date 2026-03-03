/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:39:01 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/23 14:31:02 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/* 
int	main(void)
{
	ft_putchar_fd('H', 1);
	ft_putchar_fd('i', 1);
	ft_putchar_fd('\n', 1);
	return (0);
} */
