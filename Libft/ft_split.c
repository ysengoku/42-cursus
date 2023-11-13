/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:50:03 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/13 12:42:32 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_wordcount(char const *s, char c);
static char	*copy_word(char const *src, char c, int start);
static void	free_all(char **str, int i);

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		wordcount;
	int		i;
	int		nextword_start;

	wordcount = get_wordcount(s, c);
	new_str = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!new_str)
		return (NULL);
	i = 0;
	nextword_start = 0;
	while (i < wordcount)
	{
		new_str[i++] = copy_word(s, c, nextword_start);
		if (!new_str[i - 1])
		{
			free_all(new_str, i);
			return (NULL);
		}
		nextword_start += 1;
		while (s[nextword_start - 1] != c && s[nextword_start])
			nextword_start++;
	}
	new_str[i] = NULL;
	return (new_str);
}

static int	get_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	if (!s[i])
		return (0);
	count = 1;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*copy_word(char const *src, char c, int start)
{
	int		i;
	int		end;
	char	*copy;

	i = 0;
	end = start;
	while (src[end] != c && src[end])
		end++;
	copy = (char *)malloc((end - start + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (start < end)
	{
		copy[i++] = src[start++];
	}
	copy[i] = '\0';
	return (copy);
}

static void	free_all(char **str, int i)
{
	while (i > 0)
		free(str[i--]);
	free(str);
}
/*
int	main(int argc, char **argv)
{
	int		i = 0;
	char	**array;
	
	if (argc != 3)
		return 0;
	array = ft_split(argv[1], argv[2][0]);
	while (array[i])
	{
		printf("%s\n", array[i++]);
	}
	return 0;
}
*/