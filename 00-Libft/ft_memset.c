/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:45:32 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/20 15:59:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memset(void *s, int c, size_t n)
s --> starting address of memory to be filled
c --> value to be filled
n --> number of bytes to be filled starting from "s"
*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <string.h>

int	main()
{
    char    s1[] = "Coucou c'est moi.";
	char	s2[] = "Coucou c'est moi.";
    int     c = '8';
    size_t  n = 5;

	printf("--- Origial version ---\n");
    printf("Before: %s\n", s1);
    memset(s1, c, n);
    printf("After: %s\n", s1);
	
	printf("--- My version ---\n");	
    printf("Before: %s\n", s2);
    ft_memset(s2, c, n);
    printf("After: %s\n", s2);

    return (0);
}
*/