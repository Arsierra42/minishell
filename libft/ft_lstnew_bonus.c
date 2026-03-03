/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:39:23 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/28 10:19:42 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/* 
int main()
{
	// Crear un nodo con contenido "Hola Mundo"
	t_list *node = ft_lstnew("Hola Mundo");

	// Verificar si el nodo fue creado correctamente
	if (node != NULL)
	{
		// Imprimir el contenido del nodo
		printf("Contenido del nodo: %s\n", (char *)node->content);
	}

	// Liberar la memoria del nodo
	free(node);

	return 0;
} */