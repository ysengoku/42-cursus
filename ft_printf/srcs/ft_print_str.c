/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:30:53 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/27 09:21:29 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_print_str(char *str)
{
	int	count;
	int	i;

	if (!str)
		return (-1);
	count = 0;
	i = 0;
	while (str[i])
		count += ft_print_char(str[i++]);
	return (count);
}
