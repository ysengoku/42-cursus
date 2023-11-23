/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:29 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/23 08:43:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	char	*nbr;
	
	if (!n)
		return (-1);
	nbr = ft_itoa(n);
	ft_putstr_fd(nbr, 1);
	return (ft_strlen(nbr));
}
