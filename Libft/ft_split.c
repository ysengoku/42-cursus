/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:50:03 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/15 15:22:38 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_wordcount(char const *s, char c);
static char	*ft_copy_word(char const *src, char c, int start);
static void	ft_freeall(char **str, int i);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		wordcount;
	int		i;
	int		word_start;

	wordcount = ft_get_wordcount(s, c);
	array = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	word_start = 0;
	while (i < wordcount)
	{
		while (s[word_start] == c)
          word_start++;
		array[i++] = ft_copy_word(s, c, word_start);
		if (!array[i - 1])
		{
			ft_freeall(array, i);
			return (NULL);
		}
		word_start += 1;
		while (s[word_start - 1] != c && s[word_start])
			word_start++;
	}
	array[i] = NULL;
	return (array);
}

static int	ft_get_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	while (s[i] == c)
		i++;
	if (!s[i])
		return (0);
	count = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1])
				count++;
		}
		i++;
	}
	return (count);
}

static char	*ft_copy_word(char const *src, char c, int start)
{
	int		i;
	int		len;
	char	*word;
	
	len = 0;
	while (src[start + len] != c && src[start + len])
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i++] = src[start++];
	}
	word[i] = '\0';
	return (word);
}

static void	ft_freeall(char **str, int i)
{
	while (i > 0)
		free(str[i--]);
	free(str);
}

int    main()
{
  char **array;
  int        i = 0;

    array = ft_split("  tripouille  42  ", ' ');
    while (array[i])
    {
        printf("%s\n", array[i++]);
    }
    return 0;
}
/*
int    main()
{
  char **array;
  int        i = 0;

    array = ft_split("--1-2--3---4----5-----42", '-');
    while (array[i])
    {
        printf("%s\n", array[i++]);
    }
    return 0;
}
*/
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