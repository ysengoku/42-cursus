/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:47:20 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/04 11:01:14 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	read_map(int fd, char **map_arr);
static void	handle_mallocfail(char **arr, char ***grid);

char	***get_mapgrid(char *mapfile, int row_count)
{
	int		fd;
	char	***mapgrid;
	char	**map_arr;
	int		i;

	fd = open_map(mapfile);
	map_arr = ft_calloc(row_count + 1, sizeof(char *));
	if (!map_arr)
		ft_error(MALLOC_FAIL, EXIT_FAILURE);
	if (read_map(fd, map_arr) == 1)
		ft_error(MALLOC_FAIL, EXIT_FAILURE);
	mapgrid = ft_calloc(row_count + 1, sizeof(char **));
	if (!mapgrid)
		handle_mallocfail(map_arr, NULL);
	i = 0;
	while (map_arr[i])
	{
		mapgrid[i] = ft_split(map_arr[i], ' ');
		if (!mapgrid[i])
			handle_mallocfail(map_arr, mapgrid);
		i++;
	}
	ft_free_strarr(map_arr);
	return (mapgrid);
}

static int	read_map(int fd, char **map_arr)
{
	char	*line;
	int		i;
	int		res;

	i = 0;
	res = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			map_arr[i++] = ft_substr(line, 0, ft_strlen(line) - 1);
		else
			map_arr[i++] = ft_strdup(line);
		free(line);
		if (!map_arr[i - 1])
			res = 1;
	}
	if (res == 1 && map_arr)
		ft_free_arr((void *)map_arr, i);
	close(fd);
	return (res);
}

static void	handle_mallocfail(char **arr, char ***grid)
{
	if (arr)
		ft_free_strarr(arr);
	if (grid)
		ft_free_strgrid(grid);
	ft_error(MALLOC_FAIL, EXIT_FAILURE);
}
