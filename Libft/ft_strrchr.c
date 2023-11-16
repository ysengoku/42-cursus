/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:20:14 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/16 14:09:24 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s) - 1;
	if (!s)
		return ((char *)s);
	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (i + 1 > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <string.h>

int	main()
{
	const char *str = "bonjour";
	const char	ch = 'b';
	
	printf("String: %s\nChar to find: %c\n", str, ch);
	printf("--- Original version ---\n");
	printf("Output: %s\n", strrchr(str, ch));
	printf("--- My version ---\n");
	printf("Output: %s\n", ft_strrchr(str, ch));

	return 0;
}
*/