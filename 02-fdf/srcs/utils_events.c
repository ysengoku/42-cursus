/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:36:15 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/04 08:10:41 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_mlxdata *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free_arr((void **)data->map.pts3d, data->map.h);
	ft_free_arr((void **)data->map.pts, data->map.h);
	exit(1);
}

void	color_transition(int *current_color, int *new_color)
{
	if (*current_color == BLUE)
		*new_color = RED;
	else if (*current_color == RED)
		*new_color = GREEN;
	else if (*current_color == GREEN)
		*new_color = BLUE;
}

void	translate_image(int keysym, t_mlxdata *data)
{
	if (keysym == XK_Left)
		data->map.offset_x -= TRANS;
	if (keysym == XK_Right)
		data->map.offset_x += TRANS;
	if (keysym == XK_Up)
		data->map.offset_y -= TRANS;
	if (keysym == XK_Down)
		data->map.offset_y += TRANS;
}

void	switch_projection(int keysym, t_mlxdata *data)
{
	if (data->map.proj == ISO && keysym == XK_p)
		data->map.proj = DIM;
	else if (data->map.proj == DIM)
	{
		if (keysym == XK_p)
			data->map.proj = ISO;
		if (keysym == XK_w && data->map.angle_dim + 5 < 45)
			data->map.angle_dim += 5;
		if (keysym == XK_s && data->map.angle_dim - 5 > 0)
			data->map.angle_dim -= 5;
	}
}

void	print_instruction(void)
{
	ft_printf
		("\n----- Mouse in one hand, keyboard in the other. Enjoy 😎 -----\n");
	write(1, "\n", 2);
	write(1, TRANSLATE, ft_strlen(TRANSLATE));
	write(1, ROTATE, ft_strlen(ROTATE));
	write(1, ALTITUDE, ft_strlen(ALTITUDE));
	write(1, TRANS_COLOR, ft_strlen(TRANS_COLOR));
	write(1, ZOOM, ft_strlen(ZOOM));
	write(1, PROJ, ft_strlen(PROJ));
	write(1, ANGLE, ft_strlen(ANGLE));
	write(1, "\n", 2);
	write(1, CLOSE, ft_strlen(CLOSE));
	ft_printf
		("--------------------------------------------------------------\n\n");
}
