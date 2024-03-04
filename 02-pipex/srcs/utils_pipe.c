/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:57:01 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/09 14:57:03 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_pipe(int (*pipefd)[2])
{
	if (pipe((*pipefd)) == -1)
		ft_perror("pipe");
}

void	dup_input(int fd_in)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_perror("dup2");
	close(fd_in);
}

void	dup_output(int fd_out)
{
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_close_and_perror(fd_out, "dup2", EXIT_FAILURE);
	close(fd_out);
}

void	dup_outfile(int cmd_count, char **argv, int pipe[2])
{
	int	fd_out;

	fd_out = open(argv[cmd_count + 2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd_out == -1)
	{
		close(pipe[READ_END]);
		close(pipe[WRITE_END]);
		ft_perror(argv[cmd_count + 2]);
	}
	else if (fd_out > 0)
	{
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			ft_close_and_perror(fd_out, "dup2", EXIT_FAILURE);
		close(fd_out);
	}
}
