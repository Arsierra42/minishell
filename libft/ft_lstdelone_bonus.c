/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:20:12 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 11:54:39 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/* void del_content(void *content)
{
	free(content);  // Liberamos el contenido del nodo
}

int main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	// Crear nodos y asignar valores
	node1 = ft_lstnew(malloc(sizeof(int)));
	*(int *)node1->content = 42;

	node2 = ft_lstnew(malloc(sizeof(int)));
	*(int *)node2->content = 24;

	node3 = ft_lstnew(malloc(sizeof(int)));
	*(int *)node3->content = 99;

	// Enlazar los nodos
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// Mostrar los valores antes de eliminar el nodo
	printf("Antes de eliminar un nodo:\n");
	printf("Nodo 1: %d\n", *(int *)node1->content);
	printf("Nodo 2: %d\n", *(int *)node2->content);
	printf("Nodo 3: %d\n", *(int *)node3->content);

	// Eliminar el nodo 2
	ft_lstdelone(node2, del_content);

	// Mostrar los valores después de eliminar el nodo
	printf("\nDespués de eliminar el nodo 2:\n");
	printf("Nodo 1: %d\n", *(int *)node1->content);
	// Como node2 fue eliminado, no lo imprimimos.
	if (node2 == NULL) {
		printf("Nodo 2 ha sido eliminado.\n");
	}
	printf("Nodo 3: %d\n", *(int *)node3->content);

	// Liberar el resto de la memoria de los nodos restantes
	ft_lstdelone(node1, del_content);
	ft_lstdelone(node3, del_content);

	return 0;
}
 */