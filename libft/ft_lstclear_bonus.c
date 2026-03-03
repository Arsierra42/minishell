/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:46:20 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 10:16:38 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst ||!del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
/* 
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lista;
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;

	nodo1 = ft_lstnew(ft_strdup("Uno"));
	nodo2 = ft_lstnew(ft_strdup("Dos"));
	nodo3 = ft_lstnew(ft_strdup("Tres"));

	ft_lstadd_back(&nodo1, nodo2);
	ft_lstadd_back(&nodo1, nodo3);

	lista = nodo1;

	printf("Antes de clear:\n");
	t_list *tmp = lista;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	ft_lstclear(&lista, del);

	printf("\nDespués de clear:\n");
	if (!lista)
		printf("Lista vacía\n");

	return (0);
} */