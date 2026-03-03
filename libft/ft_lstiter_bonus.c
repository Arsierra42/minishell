/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:17:41 by uelizegi          #+#    #+#             */
/*   Updated: 2025/04/29 11:44:14 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* 
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("Hola"));
	t_list *node2 = ft_lstnew(ft_strdup("mundo"));
	t_list *node3 = ft_lstnew(ft_strdup("42"));

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);

	ft_lstiter(node1, print_content);

	ft_lstclear(&node1, free);
	return (0);
} */