/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:29 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/30 09:29:20 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_nbr(long n)
{
	int	count;

	if (n < 0)
		return (write(1, "-", 1) + ft_print_nbr(n * -1));
	if (n < 10)
		return (ft_print_char(n + '0'));
	count = ft_print_nbr(n / 10);
	count += ft_print_nbr(n % 10);
	return (count);
}
