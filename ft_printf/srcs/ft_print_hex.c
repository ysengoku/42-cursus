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
		base = BASE_HEXLOWER;
	else if (sp == 'X')
		base = BASE_HEXUPPER;
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

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
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
		count = 8; // when n < 0, always 8 (convert from 32 bits)
	return (count);
}

int    ft_print_hex(int n, char sp)
{
    unsigned int    nbr = n;
//    int count = 0;

    if (nbr > 15)
    {
        ft_print_hex(nbr / 16, sp);
        ft_print_hex(nbr % 16, sp);
    }
    else if (nbr >= 0 && nbr <= 9)
    {
        ft_putchar_fd(n + '0', 1);
        count += 1;
    }
    else if (nbr > 9 && nbr < 16)
    {
        if (sp == 'x')
            ft_putchar_fd('a' + nbr - 10, 1);
        else if (sp == 'X')
            ft_putchar_fd('A' + nbr - 10, 1);
        count += 1;
    }
    return (ft_get_digitcount_hex(n));
 //   return (count);
}

int main() {
    int    arg = 6908;
    
    unsigned int    n = arg;
    printf("Signed int value : %i\n", arg);
    printf("Unsigned int value : %u\n", n);
    
    printf(" (%i)\n", printf("%x", arg));
    printf(" (%i)\n", ft_print_hex(arg, 'x'));
    printf(" (%i)\n", ft_print_hex(arg, 'X'));
    return 0;
}
*/