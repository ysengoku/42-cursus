/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:41 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/21 13:05:22 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(nptr[i]))
		i++;
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
		if (nbr / 10 > INT_MAX)
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
