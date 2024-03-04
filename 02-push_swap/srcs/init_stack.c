/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:06:58 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/18 08:13:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_set_index(t_stack_node **stack);

void	ft_init_stack(t_stack_node **stack, char **av, int ac)
{
	long	value;
	size_t	i;

	i = 0;
	if (!ft_check_input(ac, av))
		ft_error();
	if (ac == 2)
	{
		av = ft_split((const char *)av[1], ' ');
		if (!av)
			ft_error();
	}
	if (ac > 2)
		i = 1;
	while (av[i])
	{
		value = ft_atol(av[i++]);
		if (value < INT_MIN || value > INT_MAX)
			ft_free_and_error(stack, ac, av);
		if (!ft_append_node(stack, (int)value))
			ft_free_and_error(stack, ac, av);
	}
	if (ac == 2)
		ft_free_str_arr(av);
	ft_set_index(stack);
}

static void	ft_set_index(t_stack_node **stack)
{
	size_t			stack_size;
	size_t			i;
	t_stack_node	*next_node;

	stack_size = ft_stacksize(stack);
	if (stack_size <= 20)
		return ;
	i = 0;
	while (i < stack_size)
	{
		next_node = ft_get_min_node(stack);
		next_node->index = i;
		i++;
	}
}
