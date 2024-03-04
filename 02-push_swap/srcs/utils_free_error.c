/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:55:01 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/15 07:55:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_str_arr(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	ft_free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
	*stack = NULL;
}

void	ft_free_and_error(t_stack_node **a, int ac, char **av)
{
	ft_free_stack(a);
	if (ac == 2)
		free(av);
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
