/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:27:17 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/30 12:26:32 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/* 
int	main(void)
{
	char	buffer1[20] = "Hola";
	char	buffer2[11] = "Hola";
	char	buffer3[6] = "Hola";

	const char *src = " Mundo";

	size_t result1 = ft_strlcat(buffer1, src, sizeof(buffer1));
	size_t result2 = ft_strlcat(buffer2, src, sizeof(buffer2));
	size_t result3 = ft_strlcat(buffer3, src, sizeof(buffer3));

	printf("Mas espacio Test 1 (espacio suficiente)\n");
	printf("Resultado: %zu\n", result1);
	printf("Buffer: \"%s\"\n\n", buffer1);

	printf("Espacio justo Test 2 (espacio justo)\n");
	printf("Resultado: %zu\n", result2);
	printf("Buffer: \"%s\"\n\n", buffer2);

	printf("No hay suficiente espacio Test 3 (espacio insuficiente)\n");
	printf("Resultado: %zu\n", result3);
	printf("Buffer: \"%s\"\n", buffer3);

	return (0);
} 
 */