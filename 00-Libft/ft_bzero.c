/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:43 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/20 15:58:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <strings.h>

int	main()
{
	char	s1[] = "abcde12345";
	char	s2[] = "abcde12345";
	size_t n = 5;

	printf("--- Original version ---\n");
	printf("Before: %s\n", s1);
	bzero(s1, n);
	printf("After: %s\n", s1);

	printf("--- My version ---\n");
	printf("Before: %s\n", s2);
	ft_bzero(s2, n);
	printf("After: %s\n", s2);

	return 0;
}
*/