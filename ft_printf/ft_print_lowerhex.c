/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowerhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/23 14:42:50 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_get_digitcount(int n, int base);
static char	*ft_convert_negtobi(int n);
static char	*ft_itoa_base_lhex(int n);

int	ft_print_lowerhex(int n)
{
	char	*nbr;

	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', 1);
		return (1);
	}
	if (n > 9 && n < 16)
	{
		ft_putchar_fd('a' + n - 10, 1);
		return (1);
	}
	nbr = ft_itoa_base_lhex(n);
	ft_putstr_fd(nbr, 1);
	return (ft_strlen(nbr));
}

static unsigned int	ft_get_digitcount(int n, int base)
{
	unsigned int	count;

	if (n > 0)
	{
		count = 0;
		while(n > 0)
		{
			n /= base;
			count++; 
		}
	}
	else
	{

	}
	if (base == 2 && count % 4 != 0)
		count += 4 - count % 4; // in binary, count has to be a multiple of 4 
	return (count);
}

static char	*ft_convert_negtobi(int n)
{
	char			*res;
	unsigned int	count;

	n *= -1; // get the absolute value
	count = ft_get_digitcount(n, 2);
	res = (char *)ft_calloc(count + 1, sizeof(char));
	while (n > 0)
	{
		res[--count] = (n % 2)  + '0';
		n /= 2;
	}
	while (count-- > 0)
		res[count] = '0';
	while (res[count++] != '\0')
	{
		if (res[count - 1] == '0')
			res[count - 1] = '1';
		else if (res[count - 1] == '1')
			res[count -1] = '0';
	}
	// add 0001 to res
	return (res);
}

static char	*ft_itoa_base_lhex(int n)
{
	char	*base;
	char	*nbr;
	int		digitcount;

	base = "0123456789abcdef";
	digitcount = ft_get_digitcount(n, 16);
	
	nbr = (char *)ft_calloc(digitcount + 1, sizeof(char));
	if (n > 0)
	{
		while (n > 0)
		{
			nbr[--digitcount] = base[n % 16];
			n /= 16;  
		}
	}
	
	return (nbr);
}
