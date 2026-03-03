/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type	lexer_op_type(const char *s, size_t *i)
{
	if (s[*i] == '|' && s[*i + 1] == '|')
		return ((*i) += 2, TOKEN_OR);
	if (s[*i] == '|')
		return ((*i)++, TOKEN_PIPE);
	if (s[*i] == '&' && s[*i + 1] == '&')
		return ((*i) += 2, TOKEN_AND);
	if (s[*i] == '&')
		return ((*i)++, TOKEN_INVALID);
	if (s[*i] == '<' && s[*i + 1] == '<')
		return ((*i) += 2, TOKEN_HEREDOC);
	if (s[*i] == '>' && s[*i + 1] == '>')
		return ((*i) += 2, TOKEN_APPEND);
	if (s[*i] == '<')
		return ((*i)++, TOKEN_REDIR_IN);
	return ((*i)++, TOKEN_REDIR_OUT);
}
