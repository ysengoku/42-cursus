/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:14:36 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/12 15:35:20 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	skip_zero_and_plus(const char *s, size_t i);
static int		is_zero(const char *s);
static int		ft_numcmp(const char *s1, const char *s2);

int	ft_check_repeat(char **s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (!ft_numcmp(s[i], s[j++]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	is_zero(const char *s)
{
	size_t	i;

	i = 0;
	if (ft_issign((char)s[i]))
		i++;
	while (s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static size_t	skip_zero_and_plus(const char *s, size_t i)
{
	while ((s[i] == '0' || s[i] == '+') && s[i + 1] != 0)
		i++;
	return (i);
}

static int	ft_numcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (is_zero(s1) && is_zero(s2))
		return (0);
	if (s1[i] == '-' && s2[j] == '-')
	{
		i++;
		j++;
	}
	i = skip_zero_and_plus(s1, i);
	j = skip_zero_and_plus(s2, j);
	while (s1[i] || s2[j])
	{
		if (!((unsigned char)s1[i] == (unsigned char)s2[j]))
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		i++;
		j++;
	}
	return (0);
}
