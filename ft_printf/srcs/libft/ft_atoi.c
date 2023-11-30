/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:41 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/20 16:12:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res += (nptr[i] - '0');
		if (ft_isdigit(nptr[i + 1]))
			res *= 10;
		i++;
	}
	return ((int)res * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 2)
        return (0);
    printf("--- My version ---\n");
    printf("Input: %s ---> Output: %i\n", argv[1], ft_atoi(argv[1]));
    
    printf("--- Original atoi ---\n");
    printf("Input: %s ---> Output: %i\n", argv[1], atoi(argv[1]));
    
    return (0);
}
*/
