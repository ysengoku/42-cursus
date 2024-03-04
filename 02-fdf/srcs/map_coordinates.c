/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:44:26 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/28 15:47:12 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_z_and_color(t_mapdata *map, char ***mapgrid, int x, int y);
static int	init_pts3darr(t_mapdata *map);

int	get_coordinates(char *mapfile, t_mapdata *map)
{
	char	***mapgrid;
	int		y;
	int		x;

	mapgrid = get_mapgrid(mapfile, map->h);
	if (init_pts3darr(map) == -1)
		return (ft_free_strgrid(mapgrid), ft_putendl_fd(MALLOC_FAIL, 2), 1);
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			map->pts3d[y][x].x = x;
			map->pts3d[y][x].y = y;
			if (get_z_and_color(map, mapgrid, x, y) == 1)
				return (ft_free_arr((void **)map->pts3d, map->h),
					ft_free_strgrid(mapgrid), 1);
			x++;
		}
		y++;
	}
	ft_free_strgrid(mapgrid);
	return (0);
}

static int	get_z_and_color(t_mapdata *map, char ***mapgrid, int x, int y)
{
	char	**value;

	value = ft_split(mapgrid[y][x], ',');
	if (!value)
		return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
	if (!ft_isstr_int(value[0]))
		return (ft_putendl_fd(INVALID_MAP, 2), ft_free_strarr(value), 1);
	map->pts3d[y][x].z = ft_atoi(value[0]);
	if (value[1])
	{
		map->pts3d[y][x].color = ft_atoi_base16(value[1]);
		if (map->pts3d[y][x].color == -1)
			return (ft_putendl_fd(INVALID_MAP, 2), ft_free_strarr(value), 1);
	}
	else if (!value[1])
		map->pts3d[y][x].color = map->default_color;
	else
		return (ft_putendl_fd(MALLOC_FAIL, 2), ft_free_strarr(value), 1);
	return (ft_free_strarr(value), 0);
}

static int	init_pts3darr(t_mapdata *map)
{
	int	i;

	i = 0;
	map->pts3d = malloc(map->h * sizeof(t_point3d *));
	if (!map->pts3d)
		return (-1);
	while (i < map->h)
	{
		map->pts3d[i] = malloc(map->w * sizeof(t_point3d));
		if (!map->pts3d[i])
		{
			while (i > 0)
				free(map->pts3d[i--]);
			free(map->pts3d);
			return (-1);
		}
		i++;
	}
	return (0);
}
