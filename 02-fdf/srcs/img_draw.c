/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 07:54:41 by yusengok          #+#    #+#             */
/*   Updated: 2024/02/28 15:26:15 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	plot_points(t_mlxdata *data, t_point p1, t_point p2);
static void	put_gradient_pxl(t_mlxdata *data, t_line line);

void	draw_x(int i, t_mlxdata *data)
{
	int	j;

	j = 0;
	while (j < data->map.w - 1)
	{
		plot_points(data, data->map.pts[i][j], data->map.pts[i][j + 1]);
		j++;
	}
}

void	draw_y(int i, t_mlxdata *data)
{
	int	j;

	j = 0;
	while (j < data->map.h - 1)
	{
		plot_points(data, data->map.pts[j][i], data->map.pts[j + 1][i]);
		j++;
	}
}

static int	plot_points(t_mlxdata *data, t_point p1, t_point p2)
{
	float	dx;
	float	dy;
	t_line	line;

	line.start.x = p1.x * data->map.scale + data->map.offset_x;
	line.start.y = p1.y * data->map.scale + data->map.offset_y;
	line.end.x = p2.x * data->map.scale + data->map.offset_x;
	line.end.y = p2.y * data->map.scale + data->map.offset_y;
	line.start.color = p1.color;
	line.end.color = p2.color;
	dx = line.end.x - line.start.x;
	dy = line.end.y - line.start.y;
	if (fabsf(dx) >= fabsf(dy))
		line.steps = fabsf(dx);
	else
		line.steps = fabsf(dy);
	line.xinc = dx / line.steps;
	line.yinc = dy / line.steps;
	put_gradient_pxl(data, line);
	return (0);
}

static void	put_gradient_pxl(t_mlxdata *data, t_line line)
{
	float	r_inc;
	float	g_inc;
	float	b_inc;
	int		pixcolor;
	t_color	color;

	pixcolor = line.start.color;
	color.r = (pixcolor >> 16) & 0xFF;
	color.g = (pixcolor >> 8) & 0xFF;
	color.b = pixcolor & 0xFF;
	r_inc = (((int)line.end.color >> 16) - color.r) / line.steps;
	g_inc = ((((int)line.end.color >> 8) & 0xFF) - color.g) / line.steps;
	b_inc = ((((int)line.end.color) & 0xFF) - color.b) / line.steps;
	while (line.steps-- > 0)
	{
		put_pxl_color(&data->img, (int)line.start.x, (int)line.start.y,
			pixcolor);
		line.start.x += line.xinc;
		line.start.y += line.yinc;
		color.r += r_inc;
		color.g += g_inc;
		color.b += b_inc;
		pixcolor = ((int)color.r << 16) + ((int)color.g << 8) + (int)color.b;
	}
	put_pxl_color(&data->img, (int)line.end.x, (int)line.end.y, pixcolor);
}

void	put_pxl_color(t_imgdata *img, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pxl = img->addr + (y * img->line_len + x * (img->bits_per_pxl / 8));
		*(int *)pxl = color;
	}
}
