/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:38:38 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/17 13:01:17 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <string.h>

int	main()
{
	const char	*str = "Coucou c'est moi.";
	const char	ch = 'o';
	
	printf("--- Original version ---\n");
	printf("String: %s\nChar to find: %c\n", str, ch);
	printf("Output: %s\n", strchr(str, ch));

	printf("--- My version ---\n");
	printf("String: %s\nChar to find: %c\n", str, ch);
	printf("Output: %s\n", ft_strchr(str, ch));
	
	return 0;
}
*/