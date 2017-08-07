/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_parse_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 18:15:05 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/31 19:05:59 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool		wolf_put_texture(t_wolf *wolf, t_textures *texture, char *adress)
{
	static int resolution[2] = {64, 64};

	texture->image = mlx_xpm_file_to_image(MLX.mlx, adress,
		&resolution[0], &resolution[1]);
	texture->data = mlx_get_data_addr(texture->image,
		&texture->bits, &texture->size_line, &texture->endian);
	return ((t_bool)1);
}

void		wolf_inject_textures(t_wolf *wolf)
{
	short		iter;
	static int	res[2] = {512, 512};
	static char	*textures[7] = {"pics/wood.xpm", "pics/bluestone.xpm",
	"pics/mossy.xpm", "pics/redbrick.xpm",
	"pics/floor.xpm", "pics/sand2.xpm",
	"pics/blood.xpm"};

	iter = -1;
	while (++iter < 6)
		wolf_put_texture(wolf, &TEXTURES[iter], textures[iter]);
	TEXTURES[iter].image = mlx_xpm_file_to_image(MLX.mlx,
		textures[iter], &res[0], &res[1]);
	TEXTURES[iter].data = mlx_get_data_addr(TEXTURES[iter].image,
		&TEXTURES[iter].bits,
		&TEXTURES[iter].size_line, &TEXTURES[iter].endian);
}
