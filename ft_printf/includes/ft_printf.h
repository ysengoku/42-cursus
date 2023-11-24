/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:34:37 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/24 11:11:52 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define MAX_BIT 32
# define BASE_HEXLOWER "0123456789abcdef"
# define BASE_HEXUPPER "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *arg);
int	ft_print_nbr(int n);
int	ft_print_unit(int n);
int	ft_print_hex(int n, char sp);

#endif