/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:15:08 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/29 12:45:03 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*
#define M 1024 * 1024
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

 int main(int argc, char const *argv[])
{
	char *data = malloc(4 * M);
	memset(data, 'o', 4 * M);
	data[4 * M - 1] = '\0';
	ft_putstr_fd(data, 1);
	free(data);
	return 0;
}
*/