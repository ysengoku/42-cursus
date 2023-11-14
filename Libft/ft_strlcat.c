/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:39:23 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 09:10:38 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			dst_len;
	size_t			src_len;
	unsigned int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int     main(void)
{
    printf("--- My version ---\n");
    
    const char    src[] = "123456789";

    size_t  size1 = 2;
    char    dst1[] = "ABCDE";
    printf("Before: dest === %s source === %s \
    size === %zu\n", dst1, src, size1);
    printf("After ft_strlcat: Return value %zu dest === %s\n", \
    ft_strlcat(dst1, src, size1), dst1);

    size_t size2 = 7;
    char    dst2[] = "ABCDE";
    printf("Before: dest === %s source === %s \
    size === %zu\n", dst2, src, size2);
    printf("After ft_strlcat: Return value %zu dest === %s\n", \
    ft_strlcat(dst2, src, size2), dst2);

    size_t  size3 = 15;
    char    dst3[] = "ABCDE";
    printf("Before: dest === %s source === %s \
    size === %zu\n", dst3, src, size3);
    printf("After ft_strlcat: Return value %zu dest === %s\n\n", \
    ft_strlcat(dst3, src, size3), dst3);

    printf("--- Original version ---\n");
    
    size_t  size4 = 2;
    char    dst4[] = "ABCDE";
    printf("Before: dest === %s source === %s \
    size === %zu\n", dst4, src, size4);
    printf("After ft_strlcat: Return value %zu dest === %s\n", \
    strlcat(dst4, src, size4), dst4);

    size_t  size5 = 7;
    char    dst5[] = "ABCDE";
    printf("Before: dest === %s source === %s \
    size === %zu\n", dst5, src, size5);
    printf("After ft_strlcat: Return value %zu dest === %s\n", \
    strlcat(dst5, src, size5), dst5);

    size_t  size6 = 15;
    char    dst6[] = "ABCDE";
    printf("Before: dest === %s source === %s \
    size === %zu\n", dst6, src, size6);
    printf("After ft_strlcat: Return value %zu dest === %s\n", \
    strlcat(dst6, src, size6), dst6);

    return 0;
}
*/
