/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:26 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/21 13:04:40 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;
	size_t		i;

	if (!dest && !src)
		return (dest);
	dest_ptr = (char *)dest;
	src_ptr = (const char *)src;
	i = 0;
	if (dest_ptr > src_ptr)
	{
		while (n-- > 0)
			dest_ptr[n] = src_ptr[n];
	}
	else
	{
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dest);
}
/*
Line 27 : if (dest_ptr > src_ptr)
* Check if the adress of dest is grater than the one of src.
* If true, memory overlapping may happen, 
* so we should copy from the end to avoid overwrite.
*/
/*
#include <string.h>

int	main()
{
	char	s1[] = "Hello World";
	const char	src1[] = "Coucou World";
	char	s2[] = "Hello World";
	const char	src2[] =  "Coucou World";

	printf("--- Original version ---\n");
	printf("s1: %s\nsrc: %s\n", s1, src1);
	memmove(s1, src1, sizeof(s1));
	printf("s1 after memmove: %s\n", s1);

	printf("--- My version ---\n");
	printf("s2: %s\nsrc: %s\n", s2, src2);
	ft_memmove(s2, src2, sizeof(src2));
	printf("s2 after ft_memmove: %s\n", s2);

	return 0;
}
*/
