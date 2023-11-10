/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:20:13 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/10 13:52:45 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (str[i] || i < n)
	{
		if (str[i] == c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	str[] = "abcdefgdefg";
	int	to_find = 'e';
	size_t	n = 5;

	printf("Str: %s --- to_find: %c\n", str, to_find);
	printf("Original version: %s\n", (char *)memchr(str, to_find, n));
	printf("My version: %s\n", (char *)ft_memchr(str, to_find, n));
	return 0;
}
*/