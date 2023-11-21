/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:50:45 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 09:08:26 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	i;

	if (!dest && !src)
		return (dest);
	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>

int	main()
{
	char	s1[] = "Hello World";
	char	s2[] = "Hello World";
	const char	src[] = "Coucou World";
	size_t	n = sizeof(src);

	printf("--- Original version ---\n");
	printf("s1: %s\nsrc: %s\n", s1, src);
	memcpy(s1, src, n);
	printf("s1 after memcpy: %s\n", s1);

	printf("--- My version ---\n");
	printf("s2: %s\nsrc: %s\n", s2, src);
	ft_memcpy(s2, src, n);
	printf("s2 after ft_memcpy: %s\n", s2);

	return 0;
}
*/