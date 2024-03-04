/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:28:03 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/01 09:40:01 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_background(t_mlxdata *data);
static void	adjust_altitude(t_mapdata *map);
static void	change_color(t_mapdata *map);
static void	set_projection(t_mapdata *map);

int	render_image(t_mlxdata *data)
{
	int	i;

	i = 0;
	adjust_altitude(&data->map);
	change_color(&data->map);
	set_projection(&data->map);
	if (data->win_ptr)
	{
		draw_background(data);
		while (i < data->map.h)
		{
			draw_x(i, data);
			i++;
		}
		i = 0;
		while (i < data->map.w)
		{
			draw_y(i, data);
			i++;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.img, 0, 0);
	}
	return (0);
}

static int	draw_background(t_mlxdata *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			put_pxl_color(&data->img, j++, i, BGBLACK);
		i++;
	}
	return (0);
}

static void	adjust_altitude(t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->pts3d[i][j].z != 0)
				map->pts3d[i][j].adjusted_z = map->pts3d[i][j].z
					+ map->offset_z;
			else
				map->pts3d[i][j].adjusted_z = map->pts3d[i][j].z;
			j++;
		}
		i++;
	}
}

static void	change_color(t_mapdata *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->pts3d[i][j].color == map->default_color)
				map->pts3d[i][j].color = map->new_color;
			j++;
		}
		i++;
	}
	map->default_color = map->new_color;
}

static void	set_projection(t_mapdata *map)
{
	if (map->proj == ISO)
		isometric_convert(map);
	else if (map->proj == DIM)
		dimetric_convert(map);
}
