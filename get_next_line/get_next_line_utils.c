/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:25 by yusengok          #+#    #+#             */
/*   Updated: 2023/12/11 15:20:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			{
				if (s[i] == (char)c)
					return ((char *)&s[i]);
				i++;
			}
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	res_len;
	unsigned int	i;
	unsigned int	j;

	res_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = (char *)malloc(res_len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		res[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}