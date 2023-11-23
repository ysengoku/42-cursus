/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:28:26 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/23 11:40:16 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void * arg)
{	
	if (!arg)
		return (-1);
	return (write(1, "0x", 2) + ft_print_lowerhex(arg));
}