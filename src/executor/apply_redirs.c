/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:32:47 by uelizegi          #+#    #+#             */
/*   Updated: 2026/01/27 12:08:14 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_dup2_and_close(int fd, int target_fd)
{
	if (dup2(fd, target_fd) == -1)
	{
		perror("dup2");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	open_redir_fd(t_redir *r)
{
	if (r->type == REDIR_IN)
		return (open_infile(r->file));
	if (r->type == REDIR_OUT)
		return (open_outfile_trunc(r->file));
	if (r->type == REDIR_APPEND)
		return (open_outfile_append(r->file));
	return (-1);
}

static int	apply_one_redir(t_redir *r)
{
	int	fd;

	if (!r->file)
		return (1);
	fd = open_redir_fd(r);
	if (fd == -1)
		return (1);
	if (r->type == REDIR_IN)
		return (redir_dup2_and_close(fd, STDIN_FILENO));
	return (redir_dup2_and_close(fd, STDOUT_FILENO));
}

int	apply_redirs(t_redir *r)
{
	while (r)
	{
		if (apply_one_redir(r))
			return (1);
		r = r->next;
	}
	return (0);
}
