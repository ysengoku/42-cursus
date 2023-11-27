/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:52:58 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/27 09:31:00 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static int	ft_get_digits_count(long n);

int	ft_print_uint(int n)
{
	unsigned int	nbr;
	char			*digits;
	int				count;

	nbr = (unsigned int)n;
	count = ft_get_digits_count((long)nbr);
	digits = (char *)ft_calloc(count + 1, sizeof(char));
	if (!digits)
		return (-1);
	if (nbr == 0)
		digits[--count] = '0';
	while (nbr > 0)
	{
		digits[--count] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ft_print_str(digits));
}

static int	ft_get_digits_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += 1;
		n *= -1;
	}
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
