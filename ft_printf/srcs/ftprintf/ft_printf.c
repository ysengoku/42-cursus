/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:47:32 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/24 15:24:18 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

static int	ft_print_arg(const char *format, int i, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap; // ap(argument pointer) = pointer to 'format'
	int		count;
	int		n;
	int		i;

	if (!format)
		return (-1);
	va_start(ap, format); // ap = pointer to the first argument
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			n = (int)write(1, &format[i], 1);
		else if (format[i] == '%')
			n = ft_print_arg(format, i, ap);
		if (n < 0)
			return (-1);
		count += n;
		i++;
	}
	va_end(ap);
	return (count);
}

static int	ft_print_arg(const char *format, int i, va_list ap)
{
	int	count;

	count = 0;
	if (format[i + 1] == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (format[i + 1] == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (format[i + 1] == 'p')
		count += ft_print_ptr(va_arg(ap, void *));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (format[i + 1] == 'u')
		count += ft_print_unit(va_arg(ap, int));
//	else if  (format[i + 1] == 'x' || format[i + 1] == 'X')
//		count += ft_print_hex(va_arg(ap, int), format[i + 1]);
	else if (format[i + 1] == '%')
		count += write(1, "%", 1);
	else
		return (-1);
	return (count);
}
