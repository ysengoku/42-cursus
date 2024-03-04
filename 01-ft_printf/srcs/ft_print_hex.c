/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/04 15:11:18 by yusengok         ###   ########.fr       */
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
		return (write(1, &(base[nbr]), 1));
	count = ft_print_hex(nbr / 16, sp);
	count += ft_print_hex(nbr % 16, sp);
	return (count);
}
