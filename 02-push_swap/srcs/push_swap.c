/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:33:43 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/17 15:31:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	size_t			stack_size;

	a = NULL;
	b = NULL;
	stack_size = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	ft_init_stack(&a, av, ac);
	if (ft_is_sorted(&a))
		return (ft_free_stack(&a), 0);
	stack_size = ft_stacksize(&a);
	if (stack_size <= 20)
		ft_sort_tinystack(&a, &b);
	else
		ft_radixsort(&a, &b);
	return (ft_free_stack(&a), 0);
}
