/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowerhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/22 15:38:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_digitcount(int n);
static char	*ft_itoa_base_hexl(int n);

int	ft_print_lowerhex(int n)
{
	char	*nbr;

	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', 1);
		return (1);
	}
	nbr = ft_itoa_base_hexl(n);
	ft_putstr_fd(nbr, 1);
	return (ft_strlen(nbr));
}

static int	ft_get_digitcount(int n)
{
	unsigned int	i;

	if (n > 9)
	{
		i = 0;
		while(n > 0)
		{
			n /= 16;
			i++; 
		}
	}
	else
	{

	}
	return (i);
}

static char	*ft_itoa_base_hexl(int n)
{
	char	*base;
	char	*nbr;
	int		digitcount;

	base = "0123456789abcdef";
	digitcount = ft_get_digitcount(n);
	
	nbr = (char *)malloc((digitcount + 1) * sizeof(char));
	nbr[digitcount + 1] = '\0';
	if (n > 0)
	{
		while (n > 0)
		{
			nbr[digitcount--] = base[n % 16];
			n /= 16;  
		}
	}
	return (nbr);
}
