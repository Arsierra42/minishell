/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:00:51 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 13:40:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(t_shell *sh)
{
	char	*line;

	while (!sh->should_exit)
	{
		line = readline("minishell> ");
		if (!line)
		{
			sh->should_exit = 1;
			sh->exit_code = sh->last_status;
			break ;
		}
		sh->last_status = minishell_step(sh, line);
		free(line);
	}
	write(1, "exit\n", 5);
	return (sh->exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;
	int		ret;

	(void)argc;
	(void)argv;
	sh.env = env_init(envp);
	if (!sh.env)
		return (1);
	sh.last_status = 0;
	sh.should_exit = 0;
	sh.exit_code = 0;
	setup_signals_prompt();
	ret = minishell_loop(&sh);
	rl_clear_history();
	env_free(sh.env);
	return (ret);
}
