/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:41:32 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 09:11:28 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
        return (0);
    printf("My version\n s1 === %s s2 === %s ---> %u\n", \
	argv[1], argv[2], ft_strncmp(argv[1], argv[2], atoi(argv[3])));
    printf("Original version\n s1 === %s s2 === %s ---> \
	%u\n", argv[1], argv[2], strncmp(argv[1], argv[2], atoi(argv[3])));
    return (0);
}
*/
