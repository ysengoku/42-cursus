/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:51:20 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/04 07:59:02 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_mapdata *map);
static int	ft_init_mlx(t_mlxdata *data);

int	main(int argc, char **argv)
{
	t_mlxdata	data;

	if (argc != 2 || ft_strnstr_r(argv[1], ".fdf") != 0)
		ft_error(ARG_ERROR, EXIT_FAILURE);
	init_map(&data.map);
	if (check_map(argv[1], &data.map) == 1)
		ft_error(INVALID_MAP, EXIT_FAILURE);
	if (set_map_points(argv[1], &data.map) == 1)
		ft_error(MALLOC_FAIL, EXIT_FAILURE);
	if (ft_init_mlx(&data) == 1)
		exit(EXIT_FAILURE);
	data.img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pxl,
			&data.img.line_len, &data.img.endian);
	mlx_key_hook(data.win_ptr, &handle_keyevents, &data);
	mlx_mouse_hook(data.win_ptr, &handle_mouseevents, &data.map);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&handle_closebutton, &data);
	print_instruction();
	mlx_loop_hook(data.mlx_ptr, &render_image, &data);
	mlx_loop(data.mlx_ptr);
	ft_free_arr((void **)data.map.pts3d, data.map.h);
	return (0);
}

static void	init_map(t_mapdata *map)
{
	map->h = 0;
	map->w = 0;
	map->scale = 1;
	map->angle = 30;
	map->angle_dim = 20;
	map->offset_x = 0;
	map->offset_y = 0;
	map->offset_z = 0;
	map->z_top = 0;
	map->z_bottom = 0;
	map->default_color = BLUE;
	map->new_color = BLUE;
	map->proj = ISO;
	map->pts = NULL;
	map->pts3d = NULL;
}

static int	ft_init_mlx(t_mlxdata *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
	{
		ft_putendl_fd("MLX: Initialization failed", 2);
		ft_free_arr((void **)data->map.pts3d, data->map.h);
		ft_free_arr((void **)data->map.pts, data->map.h);
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, WINNAME);
	if (!(data->win_ptr))
	{
		perror("MLX");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_free_arr((void **)data->map.pts3d, data->map.h);
		ft_free_arr((void **)data->map.pts, data->map.h);
		return (1);
	}
	return (0);
}
