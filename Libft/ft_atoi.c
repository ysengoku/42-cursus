/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:41 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/08 16:11:50 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int res;
    
    i = 0;
    while ((nptr[i] <= 9 && nptr[i] >= 13) || nptr[i] == 32)
        i++;
    if (nptr[i] == '+')
        sign = 1;
    else if (nptr[i] == '-')
        sign = -1;
    i++;

    while (nptr[i] <= '0' && nptr[i] >= '9')
    {
        res = res * 10 + (nptr[i] - '0');
        i++;
    }
    return (res * sign);
}