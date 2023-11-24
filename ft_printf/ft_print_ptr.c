/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:28:26 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/24 08:53:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *arg)
{
	char	*hex_flag;

	hex_flag = "0x";
	if (!arg)
		return (-1);
	return (write(1, hex_flag, 2) + ft_print_hex(arg, 'x'));
	// TO fix:
	// incompatible pointer to integer conversion
	// ft_print_lowerhex(int n) 4 bytes < arg == *void 8 bytes
}
