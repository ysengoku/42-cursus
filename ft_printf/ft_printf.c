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
	va_list	args; // list of arguments to be printed
	size_t	count;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format)
	{
//		while (format++ != '%')
//			--> ft_putchar(format - 1)
//		if (format == '%' && format + 1 != '%')
//			--> get type
//			--> print arg according to its type
//		else if (format == '%' && format + 1 == '%')
//			--> ft_putchar('%');
//		format++;
	}
	va_end(args);
}


static char	ft_get_flag(const char *str)
{
	size_t	i;

	i = 0;
	
}