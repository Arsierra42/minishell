/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_is_redir(t_token_type type);
int	syntax_is_logic(t_token_type type);
int	syntax_error(void);

static int	is_invalid_start(t_token *t)
{
	if (!t)
		return (0);
	if (t->type == TOKEN_INVALID)
		return (1);
	if (t->type == TOKEN_PIPE || syntax_is_logic(t->type))
		return (1);
	return (0);
}

static int	is_invalid_after_op(t_token *t)
{
	if (!t || !t->next)
		return (1);
	if (t->next->type == TOKEN_INVALID)
		return (1);
	if (t->next->type == TOKEN_PIPE || syntax_is_logic(t->next->type))
		return (1);
	return (0);
}

static int	is_invalid_redir(t_token *t)
{
	if (!t || !t->next)
		return (1);
	if (t->next->type != TOKEN_WORD)
		return (1);
	return (0);
}

int	check_syntax(t_token *t)
{
	if (!t)
		return (1);
	if (is_invalid_start(t))
		return (syntax_error());
	while (t)
	{
		if (t->type == TOKEN_INVALID)
			return (syntax_error());
		if (t->type == TOKEN_PIPE || syntax_is_logic(t->type))
			if (is_invalid_after_op(t))
				return (syntax_error());
		if (syntax_is_redir(t->type))
			if (is_invalid_redir(t))
				return (syntax_error());
		t = t->next;
	}
	return (1);
}
