/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:10:05 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/08 15:10:09 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static size_t	get_wordcount(char *s, char quote);
static void		find_next_quote(char *s, size_t *i, char quote);
static size_t	get_end(char *s, size_t start, char quote);
static char		**cpy_words(char *s, size_t count, char **arr, char quote);

char	**ft_split_quote(char *s, char quote)
{
	char	**arr;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = get_wordcount(s, quote);
	arr = ft_calloc(wordcount + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (cpy_words(s, wordcount, arr, quote));
}

static size_t	get_wordcount(char *s, char quote)
{
	size_t	i;
	size_t	count;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i])
		return (0);
	count = 1;
	while (s[i])
	{
		if (s[i] == quote)
			find_next_quote(s, &i, quote);
		else if (s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1])
				count++;
		}
		i++;
	}
	return (count);
}

static void	find_next_quote(char *s, size_t *i, char quote)
{
	(*i)++;
	while (s[*i] != quote && s[*i])
	{
		(*i)++;
		if (ft_strnstr(&s[(*i) - 2], "\\\\", 2))
			(*i)++;
	}
}

static size_t	get_end(char *s, size_t start, char quote)
{
	size_t	end;

	end = start;
	if (s[end - 1] == quote)
	{
		while (s[end] && s[end] != quote)
		{
			end++;
			if (ft_strnstr(&s[end - 2], "\\\\", 2))
				end++;
		}
		return (end);
	}
	else
	{
		while (s[end] && s[end] != ' ')
			end++;
	}
	return (end);
}

static char	**cpy_words(char *s, size_t count, char **arr, char quote)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (i < count)
	{
		while (s[start] && s[start] == ' ')
			start++;
		if (s[start] == quote)
			start++;
		end = get_end(s, start, quote);
		arr[i] = ft_substr_escape(s, start, end);
		if (arr[i] == NULL)
			return (ft_free_arr(arr), NULL);
		i++;
		start = end;
		if (s[start] == quote)
			start++;
	}
	return (arr);
}
