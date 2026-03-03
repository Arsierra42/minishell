/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:54:43 by uelizegi          #+#    #+#             */
/*   Updated: 2026/02/06 11:32:09 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sig = 0;

static void	handle_sigint_prompt(int sig)
{
	(void)sig;
	g_sig = SIGINT;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	handle_sigint_exec(int sig)
{
	(void)sig;
	g_sig = SIGINT;
	write(1, "\n", 1);
}

void	signals_prompt_handlers(void)
{
	signal(SIGINT, handle_sigint_prompt);
	signal(SIGQUIT, SIG_IGN);
}

static void	handle_sigquit_exec(int sig)
{
	(void)sig;
	g_sig = SIGQUIT;
	write(1, "Quit (core dumped)\n", 19);
}

void	signals_exec_parent_handlers(void)
{
	signal(SIGINT, handle_sigint_exec);
	signal(SIGQUIT, handle_sigquit_exec);
}
