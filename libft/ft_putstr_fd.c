/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:39:21 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/23 15:19:16 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}
/* 
int	main(void)
{
	ft_putstr_fd("Esto va a la salida estándar (pantalla)\n", 1);
	ft_putstr_fd("Esto es un mensaje de error\n", 2);
}
 */