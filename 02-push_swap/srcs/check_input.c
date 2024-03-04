/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:55:34 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/18 08:12:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_input(int ac, char **av)
{
	if (!ft_check_syntax(ac, av))
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av)
			return (0);
	}
	if (!ft_check_repeat(av))
	{
		if (ac == 2)
			ft_free_str_arr(av);
		return (0);
	}
	if (ac == 2)
		ft_free_str_arr(av);
	return (1);
}
