/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:50:03 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/10 15:50:05 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_wordcount(char *s, char c)
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

static char	*get_word() //TO WRITE
{
	//TO WRITE
}

char	**ft_split(char const	*s, char	c)
{
	char	**new_str;
	int		wordcount;
	int		i;
	char	*word;

	wordcount = get_wordcount(s, c);
	new_str = (char **)malloc(wordcount * sizeof(char *));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		word = get_word(); //TO WRITE
		new_str[i] = (char *)malloc((ft_strlen(word) + 1) * sizeof(char));
		if (new_str[i] == NULL)
			return (NULL);
		ft_strlcpy(new_str[i], word, ft_strlen(word) + 1);
		free(new_str[i]);
		i++;
	}
	return (new_str);
}