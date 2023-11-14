/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:58:06 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 16:02:17 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		tmp = i;
		while (big[tmp] == little[j])
		{
			if (!little[j + 1])
				return ((char *)&big[i]);
			j++;
			tmp++;
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <bsd/string.h>

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return 0;
	printf("--- Original version ---\n");
	printf("Big: %s\n Litte: %s\n Length: %s\n", argv[1], argv[2], argv[3]);
	printf("Output %s\n", strnstr(argv[1], argv[2], ft_atoi(argv[3])));
		 
	printf("--- My version ---\n");
	printf("Big: %s\n Litte: %s\n Length: %s\n", argv[1], argv[2], argv[3]);
	printf("Output %s\n", ft_strnstr(argv[1], argv[2], ft_atoi(argv[3])));
	
	return 0;
}

/*
char haystack[30] = "aaabcabcd";
ft_strnstr(haystack, "cd", 8)
*/