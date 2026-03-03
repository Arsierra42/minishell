/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:39:07 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/23 15:23:11 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}

/* int	main(void)
{
	// Ejemplo 1: escribir en la salida estándar (pantalla)
	ft_putendl_fd("Hola desde ft_putendl_fd!", 1);

	// Ejemplo 2: escribir en un archivo
	int fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putendl_fd("Esto se escribe en un archivo.", fd);
		close(fd);
	}
	else
	{
		ft_putendl_fd("Error al abrir el archivo.", 1);
	}
	return (0);
} */