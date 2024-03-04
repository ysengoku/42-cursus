/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:28:47 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/16 16:03:57 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	ft_get_maxbits(size_t stacksize);

void	ft_radixsort(t_stack_node **a, t_stack_node **b)
{
	size_t	i;
	size_t	j;
	size_t	maxbits;
	size_t	stacksize;

	i = 0;
	stacksize = ft_stacksize(a);
	maxbits = ft_get_maxbits(stacksize);
	while (i < maxbits)
	{
		if (ft_is_sorted(a))
			return ;
		j = 0;
		while (j++ < stacksize)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(b, a);
		i++;
	}
}

static size_t	ft_get_maxbits(size_t stacksize)
{
	size_t		max_index;
	size_t		max_bits_count;

	max_index = stacksize - 1;
	max_bits_count = 0;
	while (max_index)
	{
		max_bits_count++;
		max_index = max_index >> 1;
	}
	return (max_bits_count);
}
