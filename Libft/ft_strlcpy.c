/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/08 09:39:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_strlcpy(char *dst, const char *src, size_t size)
{
    unsigned int    i;

    i = 0;
    while(i < sizeof(src) || i < size)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (sizeof(src));
}