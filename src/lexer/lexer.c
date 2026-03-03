/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsierra <arsierra>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:32:40 by arsierra          #+#    #+#             */
/*   Updated: 2026/02/06 00:00:00 by arsierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				lexer_has_unclosed_quotes(const char *s);
t_token_type	lexer_op_type(const char *s, size_t *i);
char			*lexer_read_word(const char *s, size_t *i, int *quoted);
t_token			*lexer_new_token(t_token_type type, char *value, int quoted);
void			lexer_add_token(t_token **head, t_token **tail, t_token *new);
int				lexer_is_space(char c);
int				lexer_is_op(char c);
char			*lexer_substr_dup(const char *s, size_t start, size_t len);

static void	add_op_token(t_token **head, t_token **tail, char *input, size_t *i)
{
	size_t			start;
	t_token_type	type;
	char			*val;

	start = *i;
	type = lexer_op_type(input, i);
	val = lexer_substr_dup(input, start, *i - start);
	lexer_add_token(head, tail, lexer_new_token(type, val, 0));
}

static int	add_word_token(t_token **head, t_token **tail,
				char *input, size_t *i)
{
	char	*val;
	int		quoted;

	val = lexer_read_word(input, i, &quoted);
	if (!val)
		return (0);
	lexer_add_token(head, tail, lexer_new_token(TOKEN_WORD, val, quoted));
	return (1);
}

static int	lex_loop(t_token **head, t_token **tail, char *input)
{
	size_t	i;

	i = 0;
	while (input && input[i])
	{
		while (input[i] && lexer_is_space(input[i]))
			i++;
		if (!input[i])
			break ;
		if (lexer_is_op(input[i]))
			add_op_token(head, tail, input, &i);
		else if (!add_word_token(head, tail, input, &i))
			return (0);
	}
	return (1);
}

t_token	*lexer(char *input)
{
	t_token	*head;
	t_token	*tail;

	if (lexer_has_unclosed_quotes(input))
	{
		ft_putstr_fd("minishell: error: unclosed quotes\n", 2);
		return (NULL);
	}
	head = NULL;
	tail = NULL;
	if (!lex_loop(&head, &tail, input))
		return (free_tokens(head), NULL);
	if (!check_syntax(head))
		return (free_tokens(head), NULL);
	return (head);
}
