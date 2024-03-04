/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:43:23 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/09 14:55:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main()
{
	unsigned char	c1 = 'a';
	unsigned char	c2 = 'A';
	unsigned char	c3 = '5';
	
	printf("Input: %c\n", c1);
	printf("Original version output: %c\n", toupper(c1));
	printf("My version output: %c\n\n", ft_toupper(c1));

	printf("Input: %c\n", c2);
	printf("Original version output: %c\n", toupper(c2));
	printf("My version output: %c\n\n", ft_toupper(c2));

	printf("Input: %c\n", c3);
	printf("Original version output: %c\n", toupper(c3));
	printf("My version output: %c\n", ft_toupper(c3));

	return 0;
}
*/