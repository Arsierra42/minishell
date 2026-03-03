/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prepare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:41:12 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:21:58 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_tmp(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		perror(path);
	return (fd);
}

static int	one_heredoc(t_redir *r)
{
	char	*path;
	int		fd;

	path = heredoc_make_path();
	if (!path)
		return (1);
	fd = open_tmp(path);
	if (fd == -1)
		return (free(path), 1);
	setup_signals_heredoc();
	if (heredoc_read_to_fd(r->file, fd))
		return (close(fd), unlink(path), free(path), 1);
	close(fd);
	setup_signals_prompt();
	free(r->file);
	r->file = path;
	r->type = REDIR_IN;
	return (0);
}

int	prepare_heredocs(t_cmd *cmds)
{
	t_redir	*r;

	while (cmds)
	{
		r = cmds->redirs;
		while (r)
		{
			if (r->type == REDIR_HEREDOC && one_heredoc(r))
				return (setup_signals_prompt(), 1);
			r = r->next;
		}
		cmds = cmds->next;
	}
	return (0);
}
