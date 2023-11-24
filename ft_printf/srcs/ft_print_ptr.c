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

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_print_ptr(void *arg)
{
	char	*hex_flag;

	if (!arg)
		return (-1);
	hex_flag = "0x";
	return (write(1, hex_flag, 2) + ft_print_hex(*(int *)arg, 'x'));
}

/*
ft_print_lowerhex(int n) 4 bytes < arg == *void 8 bytes

srcs/ft_print_ptr.c:23:47: error: incompatible pointer to integer conversion passing 'int *' to parameter of type 'int'; dereference with * [-Werror,-Wint-conversion]
        return (write(1, hex_flag, 2) + ft_print_hex((int *)arg, 'x'));
                                                     ^~~~~~~~~~
                                                     *
srcs/../includes/ft_printf.h:29:22: note: passing argument to parameter 'n' here
int     ft_print_hex(int n, char sp);
                         ^
1 error generated.
*/