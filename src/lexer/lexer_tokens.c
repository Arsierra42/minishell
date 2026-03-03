/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer_has_unclosed_quotes(const char *s)
{
	int	q;

	q = 0;
	while (s && *s)
	{
		if (*s == '\'' && q != 2)
			q = (q != 1);
		else if (*s == '"' && q != 1)
			q = (q != 2) * 2;
		s++;
	}
	return (q != 0);
}

t_token	*lexer_new_token(t_token_type type, char *value, int quoted)
{
	t_token	*t;

	t = (t_token *)malloc(sizeof(t_token));
	if (!t)
		return (free(value), NULL);
	t->type = type;
	t->value = value;
	t->quoted = quoted;
	t->next = NULL;
	return (t);
}

void	lexer_add_token(t_token **head, t_token **tail, t_token *new)
{
	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
		(*tail)->next = new;
	*tail = new;
}
