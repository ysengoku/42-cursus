/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:21:46 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/09 14:36:55 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_perror(char *message)
{
	ft_putstr_fd("pipex: ", 2);
	perror(message);
	exit(EXIT_FAILURE);
}

void	ft_error(char *message)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_freearr_and_exit(char **arr, int exit_code, char *msg1, char *msg2)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(msg1, 2);
	ft_putendl_fd(msg2, 2);
	ft_free_arr(arr);
	exit(exit_code);
}

void	ft_close_and_perror(int fd, char *message, int exit_code)
{
	ft_putstr_fd("pipex: ", 2);
	perror(message);
	close(fd);
	exit(exit_code);
}
