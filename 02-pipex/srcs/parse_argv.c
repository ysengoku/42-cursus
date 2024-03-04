/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:02:48 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/08 14:56:47 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**extract_path(char **envp, char **args);
static char	*find_pathname(char **path_tab, char *cmd);
static char	**set_argv(char **cmd, char *pathname);

char	**parse_argv(char *argv, char **envp)
{
	char	**args;
	char	**cmd_argv;
	char	*pathname;

	args = get_cmdarg_arr(argv);
	if (!args)
		ft_error(MALLOC_FAIL);
	if (access(args[0], X_OK) == 0)
		pathname = ft_strdup(args[0]);
	else
		pathname = find_pathname(extract_path(envp, args), args[0]);
	if (!pathname)
		ft_freearr_and_exit(args, EXIT_FAILURE, "Error: ", MALLOC_FAIL);
	if (ft_strcmp(pathname, INVALID_CMD) == 0)
		ft_freearr_and_exit(args, EXIT_INVALID_CMD, args[0], INVALID_CMD);
	cmd_argv = set_argv(args, pathname);
	ft_free_arr(args);
	free(pathname);
	if (!cmd_argv)
		ft_error(MALLOC_FAIL);
	return (cmd_argv);
}

static char	**extract_path(char **envp, char **args)
{
	int		i;
	char	*path;
	char	**path_tab;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			if (!path)
				ft_freearr_and_exit(args, EXIT_FAILURE, "Error: ", MALLOC_FAIL);
			break ;
		}
		i++;
	}
	path_tab = ft_split(path, ':');
	free(path);
	if (!path_tab)
		ft_freearr_and_exit(args, EXIT_FAILURE, "Error: ", MALLOC_FAIL);
	return (path_tab);
}

static char	*find_pathname(char **path_tab, char *cmd_name)
{
	int		i;
	int		len;
	char	*cmd_path;

	i = 0;
	len = 0;
	while (path_tab[i])
	{
		len = ft_strlen(path_tab[i]) + ft_strlen(cmd_name) + 1;
		cmd_path = ft_calloc(len + 1, sizeof(char));
		if (!cmd_path)
			return (ft_free_arr(path_tab), NULL);
		ft_strcpy(cmd_path, path_tab[i]);
		if (cmd_path[ft_strlen(path_tab[i]) - 1] != '/')
			ft_strcat(cmd_path, "/");
		ft_strcat(cmd_path, cmd_name);
		if (access(cmd_path, X_OK) == 0)
			return (ft_free_arr(path_tab), cmd_path);
		free(cmd_path);
		i++;
	}
	ft_free_arr(path_tab);
	return (INVALID_CMD);
}

static char	**set_argv(char **args, char *pathname)
{
	char	**av;
	int		i;

	i = 0;
	while (args[i])
		i++;
	av = malloc((i + 1) * sizeof(char *));
	if (!av)
		return (NULL);
	av[0] = ft_strdup(pathname);
	if (!av[0])
		return (free(av), NULL);
	i = 1;
	while (args[i])
	{
		av[i] = ft_strdup(args[i]);
		if (!av[i])
			return (ft_free_arr(av), NULL);
		i++;
	}
	av[i] = NULL;
	return (av);
}
