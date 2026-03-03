/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:12:21 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 16:15:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <limits.h>

/* GLOBAL */
extern volatile sig_atomic_t	g_sig;

/* ENUMS */
typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_INVALID
}	t_token_type;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef enum e_op
{
	OP_NONE,
	OP_AND,
	OP_OR
}	t_op;

/* STRUCTS */
typedef struct s_token
{
	t_token_type		type;
	char				*value;
	int					quoted;
	struct s_token		*next;
}	t_token;

typedef struct s_redir
{
	t_redir_type		type;
	char				*file;
	struct s_redir		*next;
}	t_redir;

typedef struct s_cmd
{
	char				**argv;
	t_redir				*redirs;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_job
{
	t_cmd				*cmds;
	t_op				next_op;
	struct s_job		*next;
}	t_job;

typedef struct s_env
{
	char				*key;
	char				*value;
	int					exported;
	struct s_env		*next;
}	t_env;

typedef struct s_shell
{
	t_env	*env;
	int		last_status;
	int		should_exit;
	int		exit_code;
}	t_shell;

/* MAIN */
int				minishell_loop(t_shell *sh);
int				minishell_step(t_shell *sh, char *line);

/* SIGNALS */
void			setup_signals_prompt(void);
void			setup_signals_exec(void);
void			setup_signals_heredoc(void);
void			signals_prompt_handlers(void);
void			signals_exec_parent_handlers(void);

/* LEXER */
t_token			*lexer(char *input);
void			free_tokens(t_token *tokens);
int				check_syntax(t_token *tokens);

/* EXPANDER */
void			expand_tokens(t_shell *sh, t_token *tokens);
char			*expand_word(t_shell *sh, const char *s);

/* PARSER */
t_job			*parser(t_token *tokens);
void			free_jobs(t_job *jobs);
void			free_cmds(t_cmd *cmds);
void			free_redirs(t_redir *r);
int				is_redir_token(t_token_type type);
t_redir_type	token_to_redir_type(t_token_type type);
t_redir			*redir_new(t_redir_type type, char *file);
void			redir_add_back(t_redir **lst, t_redir *new_r);
char			**dup_argv_from_tokens(t_token **cur, t_redir **redirs);
int				handle_redir(t_token **cur, t_redir **redirs);

/* EXECUTOR */
int				execute(t_shell *sh, t_job *jobs);
int				exec_cmd_simple(t_shell *sh, t_cmd *cmd);
int				exec_pipeline(t_shell *sh, t_cmd *cmds);
int				exec_external_one(t_shell *sh, t_cmd *cmd);
void			exec_pipeline_child(t_shell *sh, t_cmd *cmd);
int				pipeline_wait_all(pid_t *pids, int count, pid_t last_pid);
char			*resolve_cmd_path(t_shell *sh, char *cmd);

/* REDIRECTIONS */
int				apply_redirs(t_redir *r);
int				open_infile(const char *file);
int				open_outfile_trunc(const char *file);
int				open_outfile_append(const char *file);
int				exec_redirs_only(t_cmd *cmd);

/* HEREDOC */
int				prepare_heredocs(t_cmd *cmds);
char			*heredoc_make_path(void);
int				heredoc_read_to_fd(char *lim, int fd);

/* BUILTINS */
int				is_builtin(const char *cmd);
int				exec_builtin(t_shell *sh, t_cmd *cmd);
int				builtin_echo(char **argv);
int				builtin_pwd(void);
int				builtin_env(t_shell *sh, char **argv);
int				builtin_exit(t_shell *sh, char **argv);
int				builtin_unset(t_shell *sh, char **argv);
int				builtin_export(t_shell *sh, char **argv);
int				builtin_cd(t_shell *sh, char **argv);
int				is_valid_ident(char *s);

/* ENV */
t_env			*env_init(char **envp);
char			*env_get(t_env *env, char *key);
void			env_set(t_env **env, char *key, char *value);
void			env_unset(t_env **env, char *key);
char			**env_to_array(t_env *env);
void			env_free(t_env *env);
t_env			*env_find(t_env *env, char *key);

/* UTILS */
void			fatal_error(char *msg);
void			free_str_array_null(char **arr);

#endif
