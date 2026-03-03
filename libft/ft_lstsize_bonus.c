/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:01:35 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/28 11:16:20 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/* 
int main()
{
	// Crear algunos nodos para la lista
	t_list *node1 = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("Node 2");
	t_list *node3 = ft_lstnew("Node 3");

	// Enlazar los nodos
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// Llamar a ft_lstsize para contar los nodos
	int size = ft_lstsize(node1);

	// Mostrar el resultado
	printf("Size of the list: %d\n", size);

	// Liberar memoria (no olvides liberar los nodos después de usar)
	free(node1);
	free(node2);
	free(node3);

	return 0;
} */