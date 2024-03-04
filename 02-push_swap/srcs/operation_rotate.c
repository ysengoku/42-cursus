/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:13:53 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 13:29:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	head = *stack;
	last = ft_get_lastnode(*stack);
	*stack = (*stack)->next;
	last->next = head;
	head->next = NULL;
	return (1);
}

void	ra(t_stack_node **a)
{
	if (ft_rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	if (ft_rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (ft_rotate(a) && ft_rotate(b))
		write(1, "rr\n", 3);
}
