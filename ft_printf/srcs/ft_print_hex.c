/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/27 10:42:57 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static unsigned int	ft_get_digitcount_hex(int n);
static char			*ft_itoa_hex(int n, char base);

int	ft_print_hex(int n, char sp)
{
	char	*nbr;

	if (n == 0)
		return (write(1, "0", 1));
	nbr = ft_itoa_hex(n, sp);
	return (ft_print_str(nbr));
}

static unsigned int	ft_get_digitcount_hex(int n)
{
	unsigned int	count;

	count = 0;
	if (n > 0)
	{
		while (n > 0)
		{
			n /= 16;
			count++;
		}
	}
	else
		count = MAX_BIT / 4;
	return (count);
}
/* 
* When n < 0, digit count are always 8 (convert from 32 bits)
*
* When the input is a negative int, the conversion is as bellow:
* 1. Convert the negative int (decimal) to binary
*		binary == 32 bits, here
* 2. Convert it from binary to hex 
*		4 bits == 1 digit in hex
*/

static char	*ft_itoa_hex(int n, char sp)
{
	char			*base;
	char			*digits;
	unsigned int	nbr;
	int				digitcount;

	nbr = n;
	if (sp == 'x')
		base = BASE_HEX_LOWER;
	else if (sp == 'X')
		base = BASE_HEX_UPPER;
	digitcount = ft_get_digitcount_hex(n);
	digits = (char *)ft_calloc(digitcount + 1, sizeof(char));
	while (nbr > 0)
	{
		digits[--digitcount] = base[nbr % 16];
		nbr /= 16;
	}
	return (digits);
}

/*
========== Recursive version (putnbr in hex version) ==========
#include <stdio.h>
#include <unistd.h>

int    ft_print_char(char c)
{
    return (write(1, &c, 1));
}

int    ft_print_hex(int n, char sp)
{
    unsigned int    nbr = n;
    int count;
    char  *base;

    if (sp == 'x')
      base = BASE_HEX_LOWER;
    else if (sp == 'X')
      base = BASE_HEX_UPPER;
    if (nbr < 16)
      ft_print_char(base[nbr]);
    else
    {
      count = ft_print_hex(nbr / 16, sp);
      return (count + ft_print_hex(nbr % 16, sp));
    }
}

int main() 
{
    int    arg = 1011;
    
    unsigned int    n = arg;
    printf("Signed int value : %i\n", arg);
    printf("Unsigned int value : %u\n", n);
    
    printf(" (%i)\n", printf("%x", arg));
    printf(" (%i)\n", ft_print_hex(arg, 'x'));
    printf(" (%i)\n", ft_print_hex(arg, 'X'));
    return 0;
}
*/