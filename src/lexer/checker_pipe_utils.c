/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_pipe_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:32:06 by arsierra          #+#    #+#             */
/*   Updated: 2026/01/08 12:32:11 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_pipe_error(int expect_cmd, t_token *t)
{
	if (t->type == TOKEN_PIPE && expect_cmd)
		return (1);
	if (t->type != TOKEN_PIPE)
		return (0);
	return (0);
}

int	check_syntax_pipes(t_token *t)
{
	int	expect_cmd;

	expect_cmd = 1;
	if (!t)
		return (0);
	while (t)
	{
		if (is_pipe_error(expect_cmd, t))
			return (2);
		if (t->type == TOKEN_PIPE)
			expect_cmd = 1;
		else
			expect_cmd = 0;
		t = t->next;
	}
	if (expect_cmd)
		return (2);
	return (0);
}
