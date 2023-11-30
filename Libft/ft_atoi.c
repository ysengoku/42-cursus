/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:41 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/30 11:47:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_spaces(const char *nptr)
{
	int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	return (i);
} 
static int	ft_check_overflow(long nbr, int sign, int i, const char *nptr)
{
	if (nbr > LONG_MAX / 10 || (nbr == LONG_MAX / 10 && nptr[i] - '0' > 7))
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nbr;

	i = ft_skip_spaces(nptr);
	sign = 1;
	nbr = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr += (nptr[i] - '0');
		if (ft_isdigit(nptr[i + 1]))
			nbr *= 10;
		if (ft_check_overflow(nbr, sign, i, nptr) == 0)
			return (0);
		else if (ft_check_overflow(nbr, sign, i, nptr) == -1)
			return (-1);
		i++;
	}
	return ((int)nbr * sign);
}
/*
int main(int argc, const char *argv[])
{
    if (argc != 2)
        return (0);
    printf("--- My version ---\n");
    printf("Input: %s ---> Output: %i\n", argv[1], ft_atoi(argv[1]));
    
    printf("--- Original atoi ---\n");
    printf("Input: %s ---> Output: %i\n", argv[1], atoi(argv[1]));
} 
*/
