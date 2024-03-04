/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:54:21 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 13:27:36 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_push(t_stack_node **origin, t_stack_node **dest)
{
	t_stack_node	*node_to_push;

	if (!*origin)
		return (0);
	node_to_push = *origin;
	*origin = (*origin)->next;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		*dest = node_to_push;
	}
	return (1);
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	if (ft_push(b, a))
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	if (ft_push(a, b))
		write(1, "pb\n", 3);
}
