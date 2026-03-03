/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:39:52 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:22:02 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_limiter(char *line, char *lim)
{
	size_t	len;

	if (!line || !lim)
		return (0);
	len = ft_strlen(lim);
	if (ft_strncmp(line, lim, len) != 0)
		return (0);
	return (line[len] == '\0');
}

int	heredoc_read_to_fd(char *lim, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			return (0);
		if (is_limiter(line, lim))
			return (free(line), 0);
		if (write(fd, line, ft_strlen(line)) == -1
			|| write(fd, "\n", 1) == -1)
			return (free(line), 1);
		free(line);
	}
}
