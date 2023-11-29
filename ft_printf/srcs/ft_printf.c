/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:47:32 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/29 15:40:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static int	ft_check_arg(va_list ap);
static int	ft_check_specifiers(const char *format);
static int	ft_print_arg(const char *format, int i, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		n;
	int		i;

	if (!format || !ft_check_specifiers(format))
		return (-1);
	va_start(ap, format);
//	if (!ft_check_arg(ap))
//		return (-1);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			n = (int)write(1, &format[i], 1);
		else if (format[i] == '%')
			n = ft_print_arg(format, i++, ap);
		if (n < 0)
			return (-1);
		count += n;
		i++;
	}
	va_end(ap);
	return (count);
}

static int	ft_check_arg(va_list ap)
{
	va_list ap_copy;
	
	va_copy(ap_copy, ap);
	if (va_arg(ap_copy, void *) == (void *)NULL) // This code doesn't check if arg exists or not, but if the first arg == zero (= null)
		return(0);
	return (1);
}

static int	ft_check_specifiers(const char *format)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				i++;
			else if (!ft_strchr(SPECIFIERS, format[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_print_arg(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (format[i + 1] == 's')
		return (ft_print_str(va_arg(ap, char *)));
	if (format[i + 1] == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	if (format[i + 1] == 'u')
		return (ft_print_uint(va_arg(ap, int)));
	if (format[i + 1] == 'x' || format[i + 1] == 'X')
		return (ft_print_hex(va_arg(ap, int), format[i + 1]));
	if (format[i + 1] == '%')
		return (write(1, "%", 1));
	return (-1);
}

/*
#include <stdio.h>
#include <stdarg.h>

static int    ft_check_arg(va_list ap)
{
    va_list ap_copy;
    
    va_copy(ap_copy, ap);
    if (va_arg(ap_copy, void *) == (void *)NULL)
        return(0);
    return (1);
}

int    ft_print_char(char c)
{
    return (write(1, &c, 1));
}

static int    ft_print_arg(const char *format, int i, va_list ap)
{
    if (format[i + 1] == 'c')
        return (ft_print_char(va_arg(ap, int)));
    return(-1);
}
        
int    ft_printf(const char *format, ...)
{
    va_list    ap;
    int        count;
    int        n;
    int        i;

    va_start(ap, format);
    if (!ft_check_arg(ap))
        return (-1);
    count = 0;
    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] != '%')
            n = (int)write(1, &format[i], 1);
        else if (format[i] == '%')
            n = ft_print_arg(format, i++, ap);
        if (n < 0)
            return (-1);
        count += n;
        i++;
    }
    va_end(ap);
    return (count);
}

int main() {
  //  printf("  -c (%i)\n\n", ft_printf("%c", 'A'));
    printf("  -c (%i)\n\n", ft_printf("%c"));
    printf("  -c (%i)\n\n", ft_printf("%c"), NULL);

  return 0;
}
*/