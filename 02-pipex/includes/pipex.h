/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:06:32 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/12 09:53:54 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* --- libraries --- */
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"

/* --- error messages & code definition --- */
# ifndef MALLOC_FAIL
#  define MALLOC_FAIL "malloc failed"
# endif

# ifndef INVALID_CMD
#  define INVALID_CMD ": command not found"
# endif

# ifndef INVALID_AC
#  define INVALID_AC "Invalid number of arguments"
# endif

# ifndef NO_ENVP
#  define NO_ENVP "Error: No environment defined. Program cannot proceed."
# endif

# ifndef EXIT_INVALID_CMD
#  define EXIT_INVALID_CMD 127
# endif

/* --- pipe fd --- */
# ifndef READ_END
#  define READ_END 0
# endif

# ifndef WRITE_END
#  define WRITE_END 1
# endif

/* --- parsing functions --- */
char	**parse_argv(char *argv, char **envp);
char	**get_cmdarg_arr(char *arg);
char	*ft_substr_escape(char *s, size_t start, size_t end);
char	**ft_split_quote(char *s, char quote);

/* --- error handling --- */
void	ft_perror(char *message);
void	ft_error(char *message);
void	ft_free_arr(char **str);
void	ft_freearr_and_exit(char **arr, int exit_code, char *msg1, char *msg2);
void	ft_close_and_perror(int fd, char *message, int exit_code);

/* --- utils --- */
void	init_pipe(int (*pipefd)[2]);
void	dup_input(int fd_in);
void	dup_output(int fd_out);
void	dup_outfile(int cmd_count, char **argv, int pipe[2]);
int		check_infile(char **argv, int pipe[2]);
pid_t	ft_fork(int pipe[2]);
void	execute_cmd(char *command, char **envp);

#endif