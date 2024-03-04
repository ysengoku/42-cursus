/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_datainit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 07:57:22 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/01 13:02:51 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_scale(t_point3d **coords, t_mapdata *map);
static int	check_z(t_point3d **coords, t_mapdata *map);
static void	get_z_base(t_point3d **pts3d, t_mapdata *map, int i, int j);

int	set_map_points(char *mapfile, t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	if (get_coordinates(mapfile, map) == 1)
		exit(EXIT_FAILURE);
	check_scale(map->pts3d, map);
	map->pts = malloc(map->h * sizeof(t_point *));
	if (!map->pts)
		return (ft_free_arr((void *)map->pts3d, map->h), 1);
	while (i < map->h)
	{
		map->pts[i] = malloc(map->w * sizeof(t_point));
		if (!map->pts[i])
		{
			j = 0;
			while (j < i)
				free(map->pts[j++]);
			free(map->pts);
			return (ft_free_arr((void *)map->pts3d, map->h), 1);
		}
		i++;
	}
	return (0);
}

static void	check_scale(t_point3d **pts3d, t_mapdata *map)
{
	float	z_delta;
	float	width_ratio;
	float	height_ratio;

	z_delta = check_z(pts3d, map);
	width_ratio = (CLIENT_W / ((map->w + ft_abs(map->w - map->h)) * sqrt(3)));
	height_ratio = (CLIENT_H / ((map->h + ft_abs(map->h - map->w)) + z_delta));
	if (width_ratio < height_ratio)
		map->scale = width_ratio;
	else
		map->scale = height_ratio;
	if (map->w < map->h)
		map->offset_x = WIDTH / 2
			- ((map->w + ft_abs(map->w - map->h)) * sqrt(3)) * map->scale / 2
			+ (map->h * sqrt(3) * map->scale / 2) + PADDING;
	else
		map->offset_x = WIDTH / 2
			- ((map->w + ft_abs(map->w - map->h)) * sqrt(3)) * map->scale / 2
			+ (map->w * sqrt(3) * map->scale / 2) + PADDING;
	if (map->z_top == 0 && map->z_bottom == 0)
		map->offset_y = HEIGHT / 2 - map->h * map->scale / 2 + PADDING;
	else
		map->offset_y = HEIGHT / 2
			- ((map->h + ft_abs(map->h - map->w)) + z_delta) * map->scale / 2
			+ map->z_top * map->scale;
}

static int	check_z(t_point3d **pts3d, t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->z_top < (pts3d[i][j].z))
				map->z_top = (pts3d[i][j].z);
			if (map->z_bottom > (pts3d[i][j].z))
				map->z_bottom = (pts3d[i][j].z);
			j++;
		}
		i++;
	}
	get_z_base(pts3d, map, i, j);
	return (map->z_top - map->z_bottom);
}

static void	get_z_base(t_point3d **pts3d, t_mapdata *map, int i, int j)
{
	map->z_base = map->z_top;
	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->z_base > (pts3d[i][j].z) && (pts3d[i][j].z) >= 0)
				map->z_base = (pts3d[i][j].z);
			j++;
		}
		i++;
	}
}
