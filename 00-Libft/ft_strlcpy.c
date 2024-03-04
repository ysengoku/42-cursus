/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:34:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 14:35:42 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
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