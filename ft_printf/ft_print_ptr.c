/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:28:26 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/23 15:21:42 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void * arg)
{	
	char	*hex_flag;

	hex_flag = "0x";
	if (!arg)
		return (-1);
	return (write(1, hex_flag, 2) + ft_print_lowerhex(arg));
	// TO fix:
	// ft_print_lowerhex(int n) 4 bytes < arg == *void 8 bytes
}