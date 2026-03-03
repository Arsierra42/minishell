/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:37:53 by uelizegi          #+#    #+#             */
/*   Updated: 2026/01/27 12:47:14 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join2(char *a, char *b)
{
	return (ft_strjoin(a, b));
}

static void	free_two(char *a, char *b)
{
	free(a);
	free(b);
}

static char	*fail_free(char *s)
{
	free(s);
	return (NULL);
}

static char	*make_full(char *prefix, char *num)
{
	char	*tmp;
	char	*out;

	tmp = join2(prefix, "_");
	if (!tmp)
		return (NULL);
	out = join2(tmp, num);
	free(tmp);
	return (out);
}

char	*heredoc_make_path(void)
{
	static int	id;
	char		*pid;
	char		*num;
	char		*prefix;
	char		*out;

	pid = ft_itoa((int)getpid());
	num = ft_itoa(id++);
	if (!pid || !num)
	{
		free_two(pid, num);
		return (NULL);
	}
	prefix = join2("/tmp/minishell_heredoc_", pid);
	free(pid);
	if (!prefix)
		return (fail_free(num));
	out = make_full(prefix, num);
	free(prefix);
	free(num);
	return (out);
}
