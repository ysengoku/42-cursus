/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:54:34 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 13:31:00 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_swap(t_stack_node **stack)
{
	t_stack_node	*node1;
	t_stack_node	*node2;

	if (!*stack || !(*stack)->next)
		return (0);
	node1 = *stack;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = node1;
	*stack = node2;
	return (1);
}

void	sa(t_stack_node **a)
{
	if (ft_swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	if (ft_swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (ft_swap(a) && ft_swap(b))
		write(1, "ss\n", 3);
}
