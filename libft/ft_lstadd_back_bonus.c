/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:29:35 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 11:54:36 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/* 
int	main()
{
	// Crear algunos nodos para la lista
	t_list *node1 = ft_lstnew("Node 1");
	t_list *node2 = ft_lstnew("Node 2");
	t_list *node3 = ft_lstnew("Node 3");

	// Crear una lista con el primer nodo
	t_list *list = node1;

	// Añadir nodos al final de la lista
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	// Recorrer y mostrar la lista
	t_list *temp = list;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
	temp = temp->next;
	}

	// Liberar memoria (no olvides liberar los nodos después de usarlos)
	free(node1);
	free(node2);
	free(node3);

	return 0;
} */