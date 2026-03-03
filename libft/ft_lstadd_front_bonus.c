/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:32:53 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/28 11:01:17 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/* 
int main(void)
{
	t_list *list = NULL;  // Lista inicialmente vacía
	t_list *new_node;

	// Crear el primer nodo con el contenido "Hello"
	new_node = ft_lstnew("Hello");
	ft_lstadd_front(&list, new_node);  // Añadir al frente

	// Crear el segundo nodo con el contenido "World"
	new_node = ft_lstnew("World");
	ft_lstadd_front(&list, new_node);  // Añadir al frente

	// Imprimir la lista
	t_list *temp = list;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);  // Imprimir el contenido
		temp = temp->next;  // Avanzar al siguiente nodo
	}

	return 0;
} */