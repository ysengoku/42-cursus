/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:34:37 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/22 15:15:17 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "Libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);

int	ft_print_nbr(int n);
int	ft_print_unit(int n);

#endif