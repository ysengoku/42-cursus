/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:07:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/01 13:55:09 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_map(char *mapfile)
{
	int	fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		ft_perror(mapfile, errno);
	return (fd);
}

int	ft_isstr_int(char *str)
{
	int		i;
	long	n;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	return (1);
}

static int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (!base[i])
		return (-1);
	return (i);
}

int	ft_atoi_base16(char *str)
{
	int		i;
	int		res;
	char	*base;

	res = 0;
	base = BASE_HEX_LOWER;
	if (ft_strlen(str) > 8 || ft_strncmp(str, "0x", 2) != 0)
		return (ft_putendl_fd("FdF: Invalid color code.", 2), -1);
	i = 2;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	i = 2;
	while (get_index(str[i], base) != -1 && str[i])
		res = res * 16 + get_index(str[i++], base);
	if (str[i])
		return (ft_putendl_fd("FdF: Invalid color code.", 2), -1);
	return (res);
}
