/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:42:21 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 12:36:24 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
/* 
// Función que transforma el contenido duplicando el string
void	*duplicate(void *content)
{
	return (ft_strdup((char *)content)); // Duplica el string con malloc
}

// Función que libera el contenido (para usar en lstclear/lstdelone)
void	delete(void *content)
{
	free(content); // Libera el string duplicado
}

// Función auxiliar para imprimir la lista
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

// Función principal
int	main(void)
{
	t_list	*original;
	t_list	*mapped;

	// 1. Crear lista original: ["Hola"] -> ["mundo"] -> ["42"]
	original = ft_lstnew(ft_strdup("Hola"));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("mundo")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("42")));

	// 2. Aplicar ft_lstmap: duplica cada string del original
	mapped = ft_lstmap(original, duplicate, delete);

	// 3. Imprimir ambas listas
	printf("Lista original:\n");
	print_list(original);  // Imprime: Hola, mundo, 42

	printf("\nLista mapeada:\n");
	print_list(mapped);    // Imprime: Hola, mundo, 42 (distintas direcciones)

	// 4. Liberar memoria de ambas listas
	ft_lstclear(&original, delete);
	ft_lstclear(&mapped, delete);

	return (0);
} */