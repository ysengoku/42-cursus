/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:06:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/12 09:56:34 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex(int *fd_in, int i, char **argv, char **envp)
{
	int		pipe[2];
	pid_t	child_pid;

	init_pipe(&pipe);
	if (i == 0)
		*fd_in = check_infile(argv, pipe);
	if (*fd_in > 0)
	{
		child_pid = ft_fork(pipe);
		if (child_pid == 0)
		{
			close(pipe[READ_END]);
			dup_input(*fd_in);
			dup_output(pipe[WRITE_END]);
			execute_cmd(argv[i + 2], envp);
		}
		else
		{
			close(pipe[WRITE_END]);
			close(*fd_in);
		}
	}
	*fd_in = pipe[READ_END];
}

pid_t	ft_pipex_last(char **argv, char **envp, int fd_in, int cmd_count)
{
	pid_t	child_pid;
	int		pipe[2];

	init_pipe(&pipe);
	child_pid = ft_fork(pipe);
	if (child_pid == 0)
	{
		close(pipe[READ_END]);
		dup_input(fd_in);
		dup_outfile(cmd_count, argv, pipe);
		execute_cmd(argv[cmd_count + 1], envp);
	}
	else
	{
		close(pipe[READ_END]);
		close(pipe[WRITE_END]);
		close(fd_in);
	}
	return (child_pid);
}

void	wait_children(pid_t lastchild_pid, int i)
{
	int	status;

	status = 0;
	waitpid(lastchild_pid, &status, 0);
	while (i-- > 0)
		wait(NULL);
	exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		cmd_count;
	int		fd_in;
	pid_t	lastchild_pid;

	i = 0;
	fd_in = 0;
	cmd_count = argc - 3;
	if (argc < 5)
		ft_error(INVALID_AC);
	if (!envp || !envp[0])
		ft_error(NO_ENVP);
	while (i < cmd_count - 1)
	{
		ft_pipex(&fd_in, i, argv, envp);
		i++;
	}
	lastchild_pid = ft_pipex_last(argv, envp, fd_in, cmd_count);
	wait_children(lastchild_pid, cmd_count);
	return (0);
}
