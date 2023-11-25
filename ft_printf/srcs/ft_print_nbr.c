/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:29 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/24 08:54:21 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_print_nbr(int n)
{
	char	*nbr;

//	if (n < INT_MIN && n > INT_MAX)
//		return (-1);
	nbr = ft_itoa(n);
	ft_putstr_fd(nbr, 1);
	return (ft_strlen(nbr));
}
