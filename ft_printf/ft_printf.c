/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:47:32 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/21 15:20:39 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap; // argument pointer (pointer to the list of arguments to be printed)
	int	count;
	int	i;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += (int)write(1, &format[i], 1); // Need to secure if write returns -1 (erreur)
		else if (format[i] == '%' && format[i + 1] == '%')
			count += (int)write(1, '%', 1);
//		else if (format[i] == '%' && format[i + 1] != '%')
//			--> get type & print arg according to its type & increase count
		i++;
	}
	va_end(ap);
	return (count);
}

static char	ft_print_arg(const char *str)
{
	
}