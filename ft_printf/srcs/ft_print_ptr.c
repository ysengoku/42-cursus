/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:28:26 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/27 09:27:55 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static unsigned int	ft_get_digitcount_hex(unsigned long n);
static int			ft_print_hexlong(unsigned long n, char sp);

int	ft_print_ptr(void *arg)
{
	char			*hex_flag;
	unsigned long	ptr;

	if (!arg)
		return (-1);
	ptr = (unsigned long)arg;
	hex_flag = "0x";
	return (write(1, hex_flag, 2) + ft_print_hexlong(ptr, 'x'));
}

static unsigned int	ft_get_digitcount_hex(unsigned long n)
{
	unsigned int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static int	ft_print_hexlong(unsigned long n, char sp)
{
	char			*base;
	char			*digits;
	int				digitcount;

	if (sp == 'x')
		base = BASE_HEXLOWER;
	else if (sp == 'X')
		base = BASE_HEXUPPER;
	digitcount = ft_get_digitcount_hex(n);
	digits = (char *)ft_calloc(digitcount + 1, sizeof(char));
	while (n > 0)
	{
		digits[--digitcount] = base[n % 16];
		n /= 16;
	}
	return (ft_print_str(digits));
}
