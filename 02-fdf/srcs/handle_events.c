/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:29:51 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/04 08:48:04 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keyevents(int keysym, t_mlxdata *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	translate_image(keysym, data);
	if (keysym == XK_KP_Add || keysym == XK_equal)
		data->map.offset_z += 1;
	if (keysym == XK_KP_Subtract || keysym == XK_minus)
		data->map.offset_z -= 1;
	if (keysym == XK_i)
		data->map.scale++;
	if (keysym == XK_o && data->map.scale - 1 > 0)
		data->map.scale--;
	if (keysym == XK_d && data->map.proj == ISO)
		data->map.angle += 10;
	if (keysym == XK_a && data->map.proj == ISO)
		data->map.angle -= 10;
	if (keysym == XK_c)
		color_transition(&data->map.default_color, &data->map.new_color);
	switch_projection(keysym, data);
	return (0);
}

int	handle_mouseevents(int mousecode, int x, int y, t_mapdata *map)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		map->scale++;
	if (mousecode == 5 && map->scale - 1 > 0)
		map->scale--;
	return (0);
}

int	handle_closebutton(t_mlxdata *data)
{
	close_window(data);
	return (0);
}
