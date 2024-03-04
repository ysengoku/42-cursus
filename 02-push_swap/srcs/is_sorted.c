/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:28:34 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 11:21:41 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack_node **stack)
{
	t_stack_node	*node1;
	t_stack_node	*node2;

	node1 = *stack;
	node2 = (*stack)->next;
	while (node2)
	{
		if (node1->value > node2->value)
			return (0);
		node1 = node2;
		node2 = node2->next;
	}
	return (1);
}
