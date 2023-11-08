/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/08 14:51:35 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t    i;

    i = 0;
    while(src[i] != '\0' && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (i);
}

/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main()
{
	const char	src[] = "Hello World!";
    char 	dest[20];
	size_t	size = 15;

	printf("My version: ");
	printf("%zu\n", ft_strlcpy(dest, src, size));
    
	printf("Original version: ");
	printf("%zu\n", strlcpy(dest, src, size));

	return (0);

}
*/