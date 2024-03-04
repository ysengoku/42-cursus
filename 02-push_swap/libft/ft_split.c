/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:08:43 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 14:11:19 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	ft_get_wordcount(char const *s, char c);
static void		ft_freeall(char **str, size_t i);
static char		**ft_cpy_words(char const *s, char c, size_t count, char **arr);

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**arr;

	count = ft_get_wordcount(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_cpy_words(s, c, count, arr));
}

static size_t	ft_get_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_freeall(char **str, size_t i)
{
	while ((int)i >= 0)
		free(str[i--]);
	free(str);
}

static char	**ft_cpy_words(char const *s, char c, size_t count, char **arr)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		arr[i] = ft_substr(s, start, end - start);
		if (!arr)
			return (ft_freeall(arr, i), NULL);
		start = end;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
