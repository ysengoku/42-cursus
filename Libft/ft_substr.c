/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:49:32 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/17 11:13:14 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	substring = ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 4)
		return 0;
	printf("%s\n", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
	return 0;
}
*/
/*
* s === source string for substring
* start === start index of 's' to copy
* len === max length of substring
*
* If 's' is empty ---> return NULL
* If 'start' is larger than 's' length ---> return empty substring
* 	(e.g. s:"abc", start:"5")
* If 'start' + 'len' is larger than 's' length
* ---> copy from 'start' to the end of 's'(len = 's' length - start)
	(e.g. s:"abc", start:"2", len:"5")
*/