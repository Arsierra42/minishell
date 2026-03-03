/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/08 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(long n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*s;
	int		len;

	nb = (long)n;
	len = ft_ilen(nb);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb)
	{
		s[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
