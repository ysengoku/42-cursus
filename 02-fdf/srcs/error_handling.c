/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:56:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/28 10:52:49 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_perror(char *message, int code)
{
	perror(message);
	exit(code);
}

void	ft_error(char *message, int code)
{
	ft_putendl_fd(message, 2);
	exit(code);
}
