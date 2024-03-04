/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 08:10:26 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/04 08:10:29 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_convert(t_mapdata *map)
{
	int		i;
	int		j;
	float	radian_a;
	float	radian_b;

	i = 0;
	radian_a = map->angle * M_PI / 180.0;
	radian_b = 120 * M_PI / 180.0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			map->pts[i][j].x = map->pts3d[i][j].x * cosf(radian_a)
				+ map->pts3d[i][j].y * cosf(radian_a + radian_b)
				+ map->pts3d[i][j].z * cosf(radian_a - radian_b);
			map->pts[i][j].y = map->pts3d[i][j].x * sinf(radian_a)
				+ map->pts3d[i][j].y * sinf(radian_a + radian_b)
				+ map->pts3d[i][j].adjusted_z * sinf(radian_a - radian_b);
			map->pts[i][j].color = map->pts3d[i][j].color;
			j++;
		}
		i++;
	}
}

void	dimetric_convert(t_mapdata *map)
{
	int		i;
	int		j;
	float	radian_dim;

	i = 0;
	radian_dim = map->angle_dim * M_PI / 180;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			map->pts[i][j].x = map->pts3d[i][j].x * cosf(radian_dim)
				- map->pts3d[i][j].y * cosf(radian_dim);
			map->pts[i][j].y = map->pts3d[i][j].x * sinf(radian_dim)
				+ map->pts3d[i][j].y * sinf(radian_dim)
				- map->pts3d[i][j].adjusted_z;
			map->pts[i][j].color = map->pts3d[i][j].color;
			j++;
		}
		i++;
	}
}
