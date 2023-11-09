/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:20:14 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/09 14:32:59 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen((char *)s) - 1;
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		else
			i--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	const char *str = "Coucou, c'est moi!";
	const char	ch = 'c';
	
	printf("String: %s\nChar to find: %c\n", str, ch);
	printf("--- Original version ---\n");
	printf("Output: %s\n", strrchr(str, ch));
	printf("--- My version ---\n");
	printf("Output: %s\n", ft_strrchr(str, ch));

	return 0;
}
*/