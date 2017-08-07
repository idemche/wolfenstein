/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:14:24 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/31 19:06:25 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	wolf_draw_algo_initializer(t_wolf *wolf)
{
	DISTANCE.delta.x = sqrt(1 + POW(RAY.direct.y) / POW(RAY.direct.x));
	DISTANCE.delta.y = sqrt(1 + (POW(RAY.direct.x)) / POW(RAY.direct.y));
	STEP.x = RAY.direct.x >= 0 ? 1 : -1;
	STEP.y = RAY.direct.y >= 0 ? 1 : -1;
	DISTANCE.side.x = RAY.direct.x >= 0 ?
	(MAP.x + 1 - RAY.pos.x) * DISTANCE.delta.x :
	(RAY.pos.x - MAP.x) * DISTANCE.delta.x;
	DISTANCE.side.y = RAY.direct.y >= 0 ?
	(MAP.y + 1 - RAY.pos.y) * DISTANCE.delta.y :
	(RAY.pos.y - MAP.y) * DISTANCE.delta.y;
}

static void	wolf_draw_algo(t_wolf *wolf)
{
	DRAW.stop = 0;
	while (!DRAW.stop)
	{
		if (DISTANCE.side.x >= DISTANCE.side.y)
		{
			MAP.y += STEP.y;
			DISTANCE.side.y += DISTANCE.delta.y;
			DRAW.side = 1;
		}
		else
		{
			MAP.x += STEP.x;
			DISTANCE.side.x += DISTANCE.delta.x;
			DRAW.side = 0;
		}
		if (MAP_S.data[MAP.x][MAP.y] > 0)
			DRAW.stop = 1;
	}
}

static void	wolf_raycasting_initialize(t_wolf *wolf)
{
	COORDS.camera = (POS.p_x << 1) / (double)(WHEIGHT) - 1;
	RAY = (t_ray){ (t_xy){POS.x, POS.y},
	{DIRECTION.x + PLANE.x * COORDS.camera,
		DIRECTION.y + PLANE.y * COORDS.camera}};
	MAP = (t_map){(int)RAY.pos.x, (int)RAY.pos.y};
	wolf_draw_algo_initializer(wolf);
	wolf_draw_algo(wolf);
	DISTANCE.wall_distance = (DRAW.side) ?
	(MAP.y - RAY.pos.y +
		((1 - STEP.y) >> 1)) / RAY.direct.y :
	(MAP.x - RAY.pos.x +
		((1 - STEP.x) >> 1)) / RAY.direct.x;
}

void		wolf_paint_floor_n_ceiling(t_wolf *wolf)
{
	if (!KEY.textures && DRAW.start > 0)
	{
		DRAW.color = 6737151;
		POS.p_y = -1;
		if (POS.p_x < WHEIGHT && POS.p_y < WWIDTH)
			while (++POS.p_y < DRAW.start)
				ft_memcpy(&MLX.image_ref[(WHEIGHT << 2)
					* POS.p_y + (POS.p_x << 2)],
				&DRAW.color, 4);
	}
	if (DRAW.end > 0)
	{
		DRAW.color = 3355443;
		POS.p_y = DRAW.end - 1;
		if (POS.p_x < WHEIGHT && POS.p_y < WWIDTH)
			while (++POS.p_y < WWIDTH)
				ft_memcpy(&MLX.image_ref[(WHEIGHT << 2)
					* POS.p_y + (POS.p_x << 2)],
					&DRAW.color, 4);
	}
}

void		wolf_ray(t_wolf *wolf)
{
	POS.p_x = -1;
	MLX.image = mlx_new_image(MLX.mlx, WHEIGHT, WWIDTH);
	MLX.image_ref = mlx_get_data_addr(MLX.image,
		&MLX.bits, &MLX.size_line, &MLX.endian);
	(KEY.textures) ? wolf_draw_surface(wolf, "sky")
	&& wolf_draw_surface(wolf, "floor") : 0;
	while (++POS.p_x < WHEIGHT)
	{
		wolf_raycasting_initialize(wolf);
		DRAW.height = (WWIDTH / DISTANCE.wall_distance);
		if ((DRAW.start = -(DRAW.height >> 1) + (WWIDTH >> 1)) < 0)
			DRAW.start = 0;
		if ((DRAW.end = (DRAW.height >> 1) + (WWIDTH >> 1)) >= WWIDTH)
			DRAW.end = WWIDTH - 1;
		DRAW.color = DRAW.side ? 65280 : 0xFFFF00;
		wolf_paint_sides(wolf);
		wolf_paint_floor_n_ceiling(wolf);
	}
	mlx_put_image_to_window(MLX.mlx, MLX.win, MLX.image, (1L >> 1), (1L >> 1));
	mlx_destroy_image(MLX.mlx, MLX.image);
}
