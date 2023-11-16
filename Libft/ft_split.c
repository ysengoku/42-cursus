/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:50:03 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/16 09:49:07 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_wordcount(char const *s, char c);
static size_t	ft_get_wordlen(char const *s, size_t start, char c);
static void		ft_freeall(char **str, size_t i);
static char		**ft_cpy_words(char const *s, char c, size_t count, char **arr);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wordcount;

	wordcount = ft_get_wordcount(s, c);
	arr = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!arr || !s)
		return (NULL);
	ft_cpy_words(s, c, wordcount, arr);
	return (arr);
}

static size_t	ft_get_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

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

static size_t	ft_get_wordlen(char const *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start] != c)
	{
		start++;
		len++;
	}
	return (len);
}

static void	ft_freeall(char **str, size_t i)
{
	while (i > 0)
		free(str[i--]);
	free(str);
}

static char	**ft_cpy_words(char const *s, char c, size_t count, char **arr)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	**array;

	i = 0;
	start = 0;
	len = 0;
	array = arr;
	while (i < count)
	{
		while (s[start] == c)
			start++;
		len = ft_get_wordlen(s, start, c);
		array[i++] = ft_substr(s, start, len);
		if (!array[i - 1])
		{
			ft_freeall(array, i);
			return (NULL);
		}
		start += len;
	}
	arr[i] = NULL;
	return (array);
}

int    main()
{
  char **array;
  int        i = 0;

    array = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
    while (array[i])
    {
        printf("%s\n", array[i++]);
    }
    return 0;
}

/*
    array = ft_split("--1-2--3---4----5-----42", '-');
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