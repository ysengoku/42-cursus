/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:41 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/08 16:13:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int res;
    
    i = 0;
    sign = 1;
    res = 0;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
        i++;
    if (nptr[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (nptr[i] == '+')
        i++;
    while (ft_isdigit([i]))
    {
        res += (nptr[i] - '0')
        if (ft_isdigit(nptr[i + 1]))
            res *= 10;
        i++;
    }
    return (res * sign);
}