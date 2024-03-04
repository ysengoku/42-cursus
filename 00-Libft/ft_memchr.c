/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:20:13 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/15 09:03:41 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>

int	main()
{
//	int	arr[] = {-49, 49, 1, -1, 0, -2, 2};
//	int	to_find = -1;
//	size_t	n = 7;

	char	arr[] = "bonjourno";
	int	to_find = 'n';
	size_t	n = 2;

//	char	arr[] =  {0, 1, 2 ,3 ,4 ,5};
//	int	to_find = 2 + 256;
//	size_t	n = 3;

	printf("Original version: %s\n", (char *)memchr(arr, to_find, n));
	printf("My version: %s\n", (char *)ft_memchr(arr, to_find, n));
	return 0;
}
*/