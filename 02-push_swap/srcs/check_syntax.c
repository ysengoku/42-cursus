/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:57:13 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 08:02:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_multi_av(char **av, int ac);
static int	check_single_av(char *av);

int	ft_check_syntax(int ac, char **av)
{
	if (ac == 2)
	{
		if (!av[1][0])
			return (0);
		return (check_single_av(av[1]));
	}
	if (ac > 2)
		return (check_multi_av(av, ac));
	return (0);
}

static int	check_single_av(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i]) || ft_isspace(s[i]) || ft_issign(s[i])))
			return (0);
		if (ft_issign(s[i])
			&& (!(ft_isdigit(s[i + 1])) || ft_isdigit(s[i - 1])))
			return (0);
		i++;
	}
	return (1);
}

static int	check_multi_av(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j]) || ft_issign(av[i][j])))
				return (0);
			if (ft_issign(av[i][j])
				&& (!ft_isdigit(av[i][j + 1]) || ft_isdigit(av[i][j - 1])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
