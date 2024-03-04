/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:55:57 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/09 15:01:20 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main()
{
	unsigned char	c1 = 'a';
	unsigned char	c2 = 'A';
	unsigned char	c3 = '7';
	
	printf("Input: %c\n", c1);
	printf("Original version output: %c\n", tolower(c1));
	printf("Original version output: %c\n", ft_tolower(c1));

	printf("Input: %c\n", c2);
	printf("Original version output: %c\n", tolower(c2));
	printf("Original version output: %c\n", ft_tolower(c2));

	printf("Input: %c\n", c3);
	printf("Original version output: %c\n", tolower(c3));
	printf("Original version output: %c\n", ft_tolower(c3));

	return 0;
}
*/