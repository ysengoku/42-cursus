/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:39:23 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/08 09:45:35 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    unsigned int    i;
    unsigned int    j;

    i = sizeof(dst);
    j = 0;
    while(src[i] || i < size)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';
    return (i);
}