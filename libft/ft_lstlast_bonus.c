/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:19:32 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/28 11:29:10 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

	// Obtener el último nodo de la lista
	t_list *last_node = ft_lstlast(node1);

	// Mostrar el contenido del último nodo
	printf("Last node content: %s\n", (char *)last_node->content);

	// Liberar memoria (no olvides liberar los nodos después de usarlos)
	free(node1);
	free(node2);
	free(node3);

	return 0;
} */