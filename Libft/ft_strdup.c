/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:23:41 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/09 09:57:08 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (0);
    printf("Source: %s\n", argv[1]);
    printf("Copy: %s\n", ft_strdup(argv[1]));
    return (0);
}
*/
