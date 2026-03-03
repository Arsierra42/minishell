/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uelizegi <uelizegi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:39:28 by uelizegi          #+#    #+#             */
/*   Updated: 2025/05/01 11:45:28 by uelizegi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c);
static char	*fill_word(const char *str, int start, int end);
static void	*ft_free(char **strs, int count);
static int	fill_split(char **split, const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (!fill_split(split, s, c))
	{
		ft_free(split, word_count(s, c));
		return (NULL);
	}
	return (split);
}

static int	fill_split(char **split, const char *s, char c)
{
	size_t	i;
	size_t	len;
	int		j;
	int		s_word;

	i = 0;
	j = 0;
	s_word = -1;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == len) && s_word >= 0)
		{
			split[j] = fill_word(s, s_word, i);
			if (!split[j])
				return (0);
			s_word = -1;
			j++;
		}
		i++;
	}
	return (1);
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(strs[i++]);
	free(strs);
	return (NULL);
}
/* 
int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("HOLA MUNDO 42", ' ');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
} */