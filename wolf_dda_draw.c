/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_dda_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:26:21 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/31 19:05:51 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	wolf_draw_by_pixel(t_wolf *wolf, int y)
{
	if (!KEY.textures && POS.p_x < WHEIGHT && y < WWIDTH)
		ft_memcpy(&MLX.image_ref[(WHEIGHT << 2) * y + (POS.p_x << 2)],
			&DRAW.color, 4);
	else if (KEY.textures && POS.p_x < WHEIGHT && y < WWIDTH)
	{
		CTEXTURES.y =
		abs(((((((y << 8) - (WWIDTH << 7) + ((DRAW.height << 7))) << 6)))
			/ DRAW.height) >> 8);
		ft_memcpy(&MLX.image_ref[(WHEIGHT << 2) * y + (POS.p_x << 2)],
			&TEXTURES[wolf->element].data[CTEXTURES.y % 64 *
				TEXTURES[wolf->element].size_line +
				(CTEXTURES.x % 64 *
					TEXTURES[wolf->element].bits >> 3)], 4);
	}
}

t_bool		wolf_draw_surface(t_wolf *wolf, char *surface)
{
	CTEXTURES.x = -1;
	if (!ft_strcmp("sky", surface))
		while ((++CTEXTURES.x < WHEIGHT) && (CTEXTURES.y = -1))
			while (++CTEXTURES.y < (WWIDTH >> 1))
				ft_memcpy(&MLX.image_ref[(WHEIGHT << 2)
					* CTEXTURES.y + (CTEXTURES.x << 2)],
					&TEXTURES[6].data[CTEXTURES.y % 512
						* TEXTURES[6].size_line +
						CTEXTURES.x % 512 * (TEXTURES[6].bits >> 3)], 4);
	return ((t_bool)1);
}

void		wolf_paint_sides(t_wolf *wolf)
{
	int iter;

	iter = DRAW.start;
	if (KEY.textures)
	{
		wolf->element = MAPDATA[MAP.x][MAP.y];
		DRAW.wall_x = (DRAW.side) ?
		RAY.pos.x + DISTANCE.wall_distance * RAY.direct.x :
		RAY.pos.y + DISTANCE.wall_distance * RAY.direct.y;
		CTEXTURES.x = (int)(DRAW.wall_x * 64);
		if ((!DRAW.side && RAY.direct.x > 0) || (DRAW.side && RAY.direct.y < 0))
			CTEXTURES.x = 63 - CTEXTURES.x;
		CTEXTURES.x = abs(CTEXTURES.x);
	}
	while (iter <= DRAW.end)
		wolf_draw_by_pixel(wolf, iter++);
}
