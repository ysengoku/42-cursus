/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:55:08 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 11:08:57 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*ft_newnode(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_stack_node	*ft_get_lastnode(t_stack_node *stack_head)
{
	t_stack_node	*last_node;

	last_node = stack_head;
	if (!stack_head)
		return (NULL);
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

int	ft_append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return (0);
	new_node = ft_newnode(value);
	if (!new_node)
		return (0);
	last_node = ft_get_lastnode(*stack);
	if (!last_node)
		(*stack) = new_node;
	else
		last_node->next = new_node;
	return (1);
}

size_t	ft_stacksize(t_stack_node **stack)
{
	size_t			size;
	t_stack_node	*tmp;

	size = 0;
	tmp = *stack;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_stack_node	*ft_get_min_node(t_stack_node **stack)
{
	t_stack_node	*min;
	t_stack_node	*tmp;

	min = *stack;
	while (min->index != -1)
		min = min->next;
	tmp = min->next;
	while (tmp)
	{
		while (tmp->index != -1)
		{
			if (!tmp->next)
				return (min);
			tmp = tmp->next;
		}
		if (min->value > tmp->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
