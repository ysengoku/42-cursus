/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:29 by yusengok          #+#    #+#             */
/*   Updated: 2024/01/09 16:15:12 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf_nbr(long n)
{
	int	count;

	if (n < 0)
		return (write(1, "-", 1) + ft_printf_nbr(n * -1));
	if (n < 10)
		return (ft_printf_char(n + '0'));
	count = ft_printf_nbr(n / 10);
	count += ft_printf_nbr(n % 10);
	return (count);
}
