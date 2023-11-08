/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:39:23 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/08 11:32:37 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    unsigned int    i;
    unsigned int    dst_len;
    unsigned int    src_len;

    i = 0;
    dst_len = ft_strlen(dst);
    src_len = sizeof(src);
    if (dst_len >= size)
        return (size + src_len);
    while(!src[i] || i < size - dst_len - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    return (dst_len + src_len);
}


#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main()
{
	const char	src[] = "World!";
    char 	dest[] = "Hello ";
	unsigned long	size = 20;

	printf("My version: ");
	printf("%zu\n", ft_strlcat(dest, src, size));

	printf("Original version: ");
	printf("%zu\n", strlcat(dest, src, size));
	return (0);

}
