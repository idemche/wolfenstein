/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:18:42 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/31 19:07:45 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/includes/libft.h"
# include "miniLibX/mlx.h"
# include <math.h>

# define KEY			wolf->key
# define MAP_S			wolf->map_s
# define MLX			wolf->mlx
# define COORDS			wolf->coords
# define RAY			wolf->coords.ray
# define MAP			wolf->coords.map
# define STEP			wolf->coords.step
# define POS			wolf->coords.pos
# define DIRECTION		wolf->coords.direct
# define PLANE			wolf->coords.plane
# define DISTANCE		wolf->coords.distance
# define ACLR			wolf->coords.acceleration
# define TEXTURES		wolf->textures
# define CTEXTURES		wolf->coords.ctextures
# define MAPDATA		wolf->map_s.data
# define DRAW			wolf->draw
# define POW(x)			(x * x)
# define NEW(x, y)		(x)malloc(sizeof(x) * y)
# define NOTADIGIT(x)	(x < 48 || x > 57)
# define SPACER(x)		(x == ' ' || x == '\n')

typedef char	t_bool;
extern char		*g_map1;
extern char		*g_map2;
extern char		*g_map3;
enum			e_win_size
{
	WHEIGHT = 1024, WWIDTH = 768
};

typedef struct	s_textures
{
	void		*image;
	char		*data;
	int			bits;
	int			size_line;
	int			endian;
}				t_textures;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*image;
	void		*image_ref;
	int			bits;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct	s_map_s
{
	char		**map;
	int			**data;
	int			linelen;
	int			elements;
	short		size;
}				t_map_s;

typedef struct	s_map
{
	int			x;
	int			y;
}				t_map;

typedef struct	s_position
{
	int			p_x;
	int			p_y;
	double		x;
	double		y;
}				t_position;

typedef struct	s_xy
{
	double		x;
	double		y;
}				t_xy;

typedef struct	s_ray
{
	t_xy		pos;
	t_xy		direct;
}				t_ray;

typedef struct	s_distance
{
	t_xy		side;
	t_xy		delta;
	double		wall_distance;
}				t_distance;

typedef struct	s_acceleration
{
	double		aclr;
	double		r_aclr;
}				t_acceleration;

typedef struct	s_coords
{
	double			camera;
	t_position		pos;
	t_xy			direct;
	t_xy			plane;
	t_ray			ray;
	t_acceleration	acceleration;
	t_map			ctextures;
	t_distance		distance;
	t_map			map;
	t_map			step;
}				t_coords;

typedef struct	s_draw
{
	int			height;
	int			side;
	int			start;
	int			stop;
	int			end;
	int			color;
	double		wall_x;
}				t_draw;

typedef struct	s_key
{
	int			forward : 2;
	int			backwards : 2;
	int			left : 2;
	int			right : 2;
	int			hints : 2;
	int			textures : 2;
}				t_key;

typedef struct	s_wolf
{
	char		*level;
	int			element;
	char		**argv;
	t_mlx		mlx;
	t_map_s		map_s;
	t_key		key;
	t_coords	coords;
	t_textures	textures[9];
	t_draw		draw;
}				t_wolf;

/*
**		PARSE_MAP
*/

void			wolf_parse_map(t_wolf *wolf);

/*
**      DDA
*/

t_bool			wolf_draw_surface(t_wolf *wolf, char *surface);
void			wolf_paint_sides(t_wolf *wolf);

/*
**		AUX
*/

int				wolf_atoi(char *str);
t_bool			wolf_free_map(char **map);
t_bool			wolf_free_data(int **data, int size);
short			wolf_map_size(t_wolf *wolf);

/*
**      KEYS
*/

int				wolf_exit(void);
int				wolf_movement(t_wolf *wolf);
int				wolf_show_hints(t_wolf *wolf);
int				wolf_key_press(int keycode, t_wolf *wolf);
int				wolf_key_release(int keycode, t_wolf *wolf);

/*
**      Raycasting
*/

void			wolf_ray(t_wolf *wolf);

/*
**       ADDITIONAL
*/

void			wolf_data_init(t_wolf *wolf);
void			wolf_inject_textures(t_wolf *wolf);

#endif
