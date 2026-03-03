/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_jobs_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 00:00:00 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_add_back(t_cmd **list, t_cmd *new)
{
	t_cmd	*tmp;

	if (!new)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	job_add_back(t_job **list, t_job *new)
{
	t_job	*tmp;

	if (!new)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_job	*job_new(t_cmd *cmds)
{
	t_job	*j;

	j = (t_job *)malloc(sizeof(t_job));
	if (!j)
		return (NULL);
	j->cmds = cmds;
	j->next_op = OP_NONE;
	j->next = NULL;
	return (j);
}
