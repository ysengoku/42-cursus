/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:20:13 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 14:23:29 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == ch)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>

int	main()
{
	int	arr[] = {-49, 49, 1, -1, 0, -2, 2};
	int	to_find = -1;
	size_t	n = 7;

	printf("Str:  --- to_find: %c\n", to_find);
	printf("Original version: %s\n", (char *)memchr(arr, to_find, n));
	printf("My version: %s\n", (char *)ft_memchr(arr, to_find, n));
	return 0;
}
*/