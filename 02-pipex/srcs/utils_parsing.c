/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:09:42 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/08 15:09:44 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char		check_quote(char *arg, size_t *i);

char	**get_cmdarg_arr(char *arg)
{
	char	quote;
	size_t	i;

	i = 0;
	quote = check_quote(arg, &i);
	if (quote == 0)
		return (ft_split((const char *)arg, ' '));
	while (arg[i++])
	{
		if (arg[i - 1] == quote)
			break ;
		if (!arg[i])
			ft_error("missing end quote");
	}
	return (ft_split_quote(arg, quote));
}

static	char	check_quote(char *arg, size_t *i)
{
	char	quote;

	quote = 0;
	while (arg[(*i)++])
	{
		if (arg[(*i) - 1] == '\'')
		{
			quote = '\'';
			break ;
		}
		else if (arg[(*i) - 1] == '\"')
		{
			quote = '\"';
			break ;
		}
	}
	return (quote);
}

char	*ft_substr_escape(char *s, size_t start, size_t end)
{
	char	*substring;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = start;
	len = end - start;
	while (j < end)
	{
		if (ft_strnstr(&s[j], "\\\\", 2))
			len -= 2;
		j++;
	}
	substring = ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (NULL);
	while (start < end)
	{
		if (ft_strnstr(&s[start], "\\\\", 2))
			start += 2;
		substring[i++] = s[start++];
	}
	return (substring);
}
