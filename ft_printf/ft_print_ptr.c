/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:28:26 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/24 09:33:50 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *arg)
{
	char	*hex_flag;

	if (!arg)
		return (-1);
	hex_flag = "0x";
	return (write(1, hex_flag, 2) + ft_print_hex((int *)arg, 'x'));

	// ft_print_lowerhex(int n) 4 bytes < arg == *void 8 bytes
}
