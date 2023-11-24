/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:52:58 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/24 08:54:33 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_print_uint(int n)
{
	unsigned long	u_nbr;
	char			*nbr;

	if (n < 0)
		u_nbr = n + 1 + UINT_MAX;
	else
	u_nbr = n;
	nbr = ft_itoa(u_nbr);
	ft_putstr_fd(nbr, 1);
	return (ft_strlen(nbr));
}
