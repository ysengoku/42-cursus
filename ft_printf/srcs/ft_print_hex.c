/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/30 09:29:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_hex(int n, char sp)
{
	unsigned int	nbr;
	int				count;
	char			*base;

	nbr = n;
	if (sp == 'x')
		base = BASE_HEX_LOWER;
	else if (sp == 'X')
		base = BASE_HEX_UPPER;
	if (nbr < 16)
		return (ft_print_char(base[nbr]));
	count = ft_print_hex(nbr / 16, sp);
	return (count + ft_print_hex(nbr % 16, sp));
}
