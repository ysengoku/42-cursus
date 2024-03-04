/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:26:11 by yusengok          #+#    #+#             */
/*   Updated: 2024/03/04 08:12:49 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ----- libraries ----- */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

/* ----- type definition ----- */
typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}				t_color;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pxl;
	int		line_len;
	int		endian;
}				t_imgdata;	

typedef struct s_point
{
	float	x;
	float	y;
	int		color;
}				t_point;

typedef struct s_point3d
{
	int	x;
	int	y;
	int	z;
	int	adjusted_z;
	int	color;
}				t_point3d;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	xinc;
	float	yinc;
	float	steps;
}				t_line;

typedef struct s_mapdata
{
	int			h;
	int			w;
	int			angle;
	int			angle_dim;
	float		scale;
	float		offset_x;
	float		offset_y;
	int			offset_z;
	float		z_top;
	float		z_bottom;
	float		z_base;
	int			default_color;
	int			new_color;
	int			proj;
	t_point3d	**pts3d;
	t_point		**pts;
}				t_mapdata;

typedef struct s_mlxdata
{
	t_xvar		*mlx_ptr;
	t_win_list	*win_ptr;
	t_imgdata	img;
	t_mapdata	map;
}				t_mlxdata;

/* ----- color definition ----- */
# define RED 0xFF77FF
# define GREEN 0x8DB600
# define BLUE 0x00B7CE
# define WHITE 0xFFFFFF
# define SHADOW 0x363636
# define BGBLACK 0x212121
# define BASE_HEX_LOWER "0123456789abcdef"
# define BASE_HEX_UPPER "0123456789ABCDEF"

/* ----- window definition ----- */
# define WINNAME "FdF"
# define WIDTH 1280
# define HEIGHT 720
# define CLIENT_W 1008
# define CLIENT_H 680
# define PADDING 20
# define TRANS 24

/* ----- mouse & key events ----- */
# define CLOSE "  Close window: [ESC] or [Click on x]\n"
# define TRANSLATE "  [↑ ↓ ← →]: Translate\n"
# define ROTATE "  [D/A]: Rotate clockw./counterclockw. (Isometric only)\n"
# define ALTITUDE "  [+ -]: Increase / decrease altitude\n"
# define TRANS_COLOR "  [C]: Change the default color\n"
# define ZOOM "  [I/O or Scroll up/down]: Zoom in / out\n"
# define PROJ "  [P]: Switch projection mode (Isometric <-> Dimetric)\n"
# define ANGLE "  [W/S]: Tilt up/down (Dimetric only)\n"
# define ISO 1
# define DIM 2

/* ----- math definition ----- */
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/* ----- error messages ----- */
# define ARG_ERROR "Usage: ./fdf <path/map_name.fdf>"
# define MALLOC_FAIL "FdF: Memory allocation failed"
# define INVALID_MAP "FdF: Invalid map format"

/* ----- Check & read map ----- */
int		check_map(char *mapfile, t_mapdata *map);
char	***get_mapgrid(char *mapfile, int row_count);
int		get_coordinates(char *mapfile, t_mapdata *map);
int		set_map_points(char *mapfile, t_mapdata *map);
int		open_map(char *mapfile);
int		ft_isstr_int(char *str);
int		ft_atoi_base16(char *str);

/* ----- Render image ----- */
int		render_image(t_mlxdata *data);
void	draw_x(int i, t_mlxdata *data);
void	draw_y(int i, t_mlxdata *data);
void	put_pxl_color(t_imgdata *img, int x, int y, int color);
void	isometric_convert(t_mapdata *map);
void	dimetric_convert(t_mapdata *map);

/* ----- Handle events -----*/
int		handle_keyevents(int keysym, t_mlxdata *data);
int		handle_mouseevents(int mousecode, int x, int y, t_mapdata *map);
int		handle_closebutton(t_mlxdata *data);
void	close_window(t_mlxdata *data);
void	color_transition(int *current_color, int *new_color);
void	translate_image(int keysym, t_mlxdata *data);
void	switch_projection(int keysym, t_mlxdata *data);
void	print_instruction(void);

/* ----- free ----- */
void	ft_free_strarr(char **arr);
void	ft_free_strgrid(char ***arr);
void	ft_free_arr(void **arr, int size);

/* ----- error handling ----- */
void	ft_perror(char *message, int code);
void	ft_error(char *message, int code);

#endif