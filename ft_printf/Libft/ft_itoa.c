/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:50:19 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/14 13:16:11 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_digits_count(long n);

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		count;

	nbr = n;
	count = ft_get_digits_count(nbr);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	if (nbr == 0)
		str[--count] = '0';
	while (nbr > 0)
	{
		str[--count] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}

static int	ft_get_digits_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += 1;
		n *= -1;
	}
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	printf("%s\n", ft_itoa(atoi(argv[1])));
	return 0;
}
*/