/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:42:02 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/17 13:55:57 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_get_distance_to_top(t_stack_node **stack, int min_value);
static void	ft_sort_three(t_stack_node **stack);
static void	ft_mv_to_top(t_stack_node **a, t_stack_node *min, size_t size);

void	ft_sort_tinystack(t_stack_node **a, t_stack_node **b)
{
	size_t			size;
	t_stack_node	*min_node;

	size = ft_stacksize(a);
	if (size == 2)
		sa(a);
	if (size == 3)
		ft_sort_three(a);
	if (size >= 4)
	{
		while (size > 3)
		{
			min_node = ft_get_min_node(a);
			ft_mv_to_top(a, min_node, size);
			pb(a, b);
			size--;
		}
		ft_sort_three(a);
		while (*b)
			pa(b, a);
	}
}

static	int	ft_get_distance_to_top(t_stack_node **stack, int min_value)
{
	int				distance;
	t_stack_node	*tmp;

	distance = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == min_value)
			return (distance);
		distance++;
		tmp = tmp->next;
	}
	return (distance);
}

static void	ft_sort_three(t_stack_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
	if ((*stack)->next->value > (*stack)->next->next->value)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

static void	ft_mv_to_top(t_stack_node **a, t_stack_node *min_node, size_t size)
{
	size_t			distance;
	size_t			needed_moves;

	distance = ft_get_distance_to_top(a, min_node->value);
	needed_moves = 0;
	if (distance == 0)
		return ;
	if (distance <= size / 2 && distance > 0)
	{
		needed_moves = distance;
		while (needed_moves-- > 0)
			ra(a);
	}
	else if (distance > size / 2)
	{
		needed_moves = size - distance;
		while (needed_moves-- > 0)
			rra(a);
	}
}
