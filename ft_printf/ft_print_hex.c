/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/24 08:52:06 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_get_digitcount_hex(int n);
static char			*ft_convert_negtobin(int n);
static char			*ft_itoa_hex(int n, char base);

int	ft_print_hex(int n, char sp)
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
	nbr = ft_itoa_hex(n, sp);
	ft_putstr_fd(nbr, 1);
	return (ft_strlen(nbr));
}

static unsigned int	ft_get_digitcount_hex(int n)
{
	unsigned int	count;

	if (n > 0)
	{
		count = 0;
		while (n > 0)
		{
			n /= 16;
			count++;
		}
	}
	else if (n < 0)
		count = 8; // when n < 0, always 8 (convert from 32 bits)
	return (count);
}

static char	*ft_convert_negtobin(int n)
{
	char			*res;
	unsigned int	count;

	n = n * (-1) - 1; // get the absolute value & minus 1
	count = MAX_BIT;
	res = (char *)ft_calloc(MAX_BIT + 1, sizeof(char));
	while (count > 0)
	{
		res[--count] = (n % 2) + '0';
		n /= 2;
	}
	while (res[count])
	{
		if (res[count] == '0')
			res[count++] = '1';
		else if (res[count] == '1')
			res[count++] = '0';
	}
	return (res);
}

static char	*ft_itoa_hex(int n, char sp)
{
	char	*base;
	char	*nbr;
	int		digitcount;

	if (sp == 'x')
		base = BASE_HEXLOWER;
	else if (sp == 'X')
		base = BASE_HEXUPPER;
	digitcount = ft_get_digitcount_hex(n);
	nbr = (char *)ft_calloc(digitcount + 1, sizeof(char));
	if (n > 0)
	{
		while (n > 0)
		{
			nbr[--digitcount] = base[n % 16];
			n /= 16;
		}
	}
	// negative number cases
	return (nbr);
}
