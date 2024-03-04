/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:36:11 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 13:29:19 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	last = ft_get_lastnode(*stack);
	while (tmp->next)
	{
		if (!tmp->next->next)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack_node **a)
{
	if (ft_reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	if (ft_reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (ft_reverse_rotate(a) && ft_reverse_rotate(b))
		write(1, "rrr\n", 4);
}
