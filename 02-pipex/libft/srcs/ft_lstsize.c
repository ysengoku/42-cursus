/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:33:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/25 15:44:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*i;

	if (!lst)
		return (0);
	count = 0;
	i = lst;
	while (i)
	{
		i = i->next;
		count++;
	}
	return (count);
}
