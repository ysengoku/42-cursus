/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:38:38 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 15:10:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!ft_isascii(c))
		return ((char *)s);
	if (c == '\0')
		return ((char *)&s[ft_strlen((char *)s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		else
			i++;
	}
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