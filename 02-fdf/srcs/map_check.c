/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:25:37 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/26 14:25:13 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_line_len(char *line);

int	check_map(char *mapfile, t_mapdata *map)
{
	int		fd;
	char	*line;
	int		is_rectangle;

	is_rectangle = 1;
	fd = open_map(mapfile);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 1);
	map->w = get_line_len(line);
	map->h = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (get_line_len(line) != map->w)
			is_rectangle = 0;
		map->h++;
	}
	close(fd);
	if (map->w < 2 || map->h < 2 || !is_rectangle)
		return (1);
	return (0);
}

static int	get_line_len(char *line)
{
	int	i;
	int	count;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	count = 1;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
		{
			if (line[i + 1] != ' ' && line[i + 1] != '\n' && line[i + 1])
				count++;
		}
		i++;
	}
	return (count);
}
