/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:45:32 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/09 15:37:21 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n / sizeof(s[0]))
	{
		s[i] == c;
		i++;
	}
	return (s);
}
/*
s --> starting address of memory to be filled
c --> value to be filled
n --> number of bytes to be filled starting from "s"
*/

#include <string.h>
#include <stdio.h>

int	main()
{
        char    s[] = "Coucou c'est moi.";
        int     c = 'k';
        size_t  n = 5*sizeof(char);

        printf("Before: %s\n", s);
        memset(s, c, n);
        printf("After: %s\n", s);
        return (0);

}