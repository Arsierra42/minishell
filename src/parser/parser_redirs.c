/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:08:13 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/08 10:57:28 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN
		|| type == TOKEN_REDIR_OUT
		|| type == TOKEN_APPEND
		|| type == TOKEN_HEREDOC);
}

t_redir_type	token_to_redir_type(t_token_type type)
{
	if (type == TOKEN_REDIR_IN)
		return (REDIR_IN);
	if (type == TOKEN_REDIR_OUT)
		return (REDIR_OUT);
	if (type == TOKEN_APPEND)
		return (REDIR_APPEND);
	return (REDIR_HEREDOC);
}

t_redir	*redir_new(t_redir_type type, char *file)
{
	t_redir	*r;

	r = malloc(sizeof(t_redir));
	if (!r)
		return (NULL);
	r->type = type;
	r->file = file;
	r->next = NULL;
	return (r);
}

void	redir_add_back(t_redir **lst, t_redir *new_r)
{
	t_redir	*cur;

	if (!new_r)
		return ;
	if (!*lst)
	{
		*lst = new_r;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new_r;
}

int	handle_redir(t_token **cur, t_redir **redirs)
{
	t_token_type	rtype;
	t_redir_type	rt;
	t_redir			*r;
	char			*fname;

	rtype = (*cur)->type;
	*cur = (*cur)->next;
	if (!*cur || (*cur)->type != TOKEN_WORD)
		return (0);
	fname = ft_strdup((*cur)->value);
	if (!fname)
		return (0);
	rt = token_to_redir_type(rtype);
	r = redir_new(rt, fname);
	if (!r)
		return (free(fname), 0);
	redir_add_back(redirs, r);
	*cur = (*cur)->next;
	return (1);
}
