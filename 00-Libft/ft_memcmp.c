/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:20:31 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/10 14:19:32 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	s1[] = "abcdefgh";
	char	s2[] = "abcdefgH";
	size_t	n = 10;
	
	printf("s1: %s\ns2: %s\n", s1, s2);
	printf("Original version: %i\n", memcmp(s1, s2, n));
	printf("My version: %i\n", ft_memcmp(s1, s2, n));
	return 0;
}
*/