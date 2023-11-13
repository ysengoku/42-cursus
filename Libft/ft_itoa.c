/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:50:19 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/13 14:48:10 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits_count(int n);
static char	*ft_strcpy(char *dst, char const *src);

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = get_digits_count(n);
	if (!(str = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	str[count] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	if (n == 0)
		str[--count] = '0';
	while (n > 0)
	{
		str[--count] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

static int	get_digits_count(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = 11;
	else if (n < 0)
	{
		count += 1;
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		count += 1;
	else
	{
		while (n > 0)
		{
			n /= 10;
			count++;
		}
	}
	return (count);
}

static char	*ft_strcpy(char *dst, char const *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);	
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	printf("%s\n", ft_itoa(atoi(argv[1])));
	return 0;
}