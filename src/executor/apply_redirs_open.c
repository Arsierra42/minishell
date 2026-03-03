/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirs_open.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:04:17 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:19:15 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_infile(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror(file);
	return (fd);
}

int	open_outfile_trunc(const char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

int	open_outfile_append(const char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}
