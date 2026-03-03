/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_frees.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:33:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/03 11:38:46 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirs(t_redir *r)
{
	t_redir	*next;

	while (r)
	{
		next = r->next;
		if (r->file && ft_strncmp(r->file, "/tmp/minishell_heredoc_", 22) == 0)
			unlink(r->file);
		free(r->file);
		free(r);
		r = next;
	}
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*next;
	int		i;

	while (cmds)
	{
		next = cmds->next;
		if (cmds->argv)
		{
			i = 0;
			while (cmds->argv[i])
			{
				free(cmds->argv[i]);
				i++;
			}
			free(cmds->argv);
		}
		if (cmds->redirs)
			free_redirs(cmds->redirs);
		free(cmds);
		cmds = next;
	}
}

void	print_cmds(t_cmd *cmds)
{
	int		i;
	int		n;
	t_redir	*r;

	n = 0;
	while (cmds)
	{
		printf("CMD %d:\n", n);
		i = 0;
		while (cmds->argv && cmds->argv[i])
		{
			printf("  argv[%d] = '%s'\n", i, cmds->argv[i]);
			i++;
		}
		r = cmds->redirs;
		while (r)
		{
			printf("  redir: type=%d file='%s'\n", r->type, r->file);
			r = r->next;
		}
		cmds = cmds->next;
		n++;
	}
}

void	free_jobs(t_job *jobs)
{
	t_job	*next;

	while (jobs)
	{
		next = jobs->next;
		if (jobs->cmds)
			free_cmds(jobs->cmds);
		free(jobs);
		jobs = next;
	}
}
