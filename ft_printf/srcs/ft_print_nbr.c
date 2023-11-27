/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:53:29 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/27 09:24:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

/*
int	ft_print_nbr(int n)
{
	char	*nbr;

	nbr = ft_itoa(n);
	return (ft_print_str(nbr));
}
*/
int    ft_print_char(char c)
{
    return (write(1, &c, 1));
}

int    ft_print_nbr(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	if (n < 0)
	{
		return (write(1, "-", 1) + ft_print_nbr(nbr * -1));
	} // does not work with INT_MIN because ft_print_nbr cannot accept 2147483648
	else if (nbr < 10)
		ft_print_char(nbr + '0');
	else
	{
		count = ft_print_nbr(nbr / 10);
		return (count + ft_print_nbr(nbr % 10));
	}
}
