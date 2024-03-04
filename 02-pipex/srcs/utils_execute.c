/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:56:49 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/12 10:00:36 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_infile(char **argv, int pipe[2])
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(argv[1]);
		close(pipe[WRITE_END]);
	}
	return (fd_in);
}

pid_t	ft_fork(int pipe[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(pipe[READ_END]);
		close(pipe[WRITE_END]);
		ft_perror("fork");
	}
	return (pid);
}

void	execute_cmd(char *command, char **envp)
{
	char	**cmd_argv;

	cmd_argv = parse_argv(command, envp);
	if (execve(cmd_argv[0], cmd_argv, envp) == -1)
	{
		ft_free_arr(cmd_argv);
		ft_perror("execve");
	}
}
