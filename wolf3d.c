/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:19:39 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/31 19:06:36 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_mlx_init(t_wolf *wolf)
{
	char *name;

	MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx,
		WHEIGHT, WWIDTH, name = ft_strjoin("Wolf3d :", wolf->argv[1]));
	KEY.hints = 1;
	free(name);
}

void	wolf_data_init(t_wolf *wolf)
{
	POS = (t_position){0, 0, 3, 3};
	DIRECTION = (t_xy){-1, 0};
	PLANE = (t_xy){0, 0.66};
	KEY = (t_key){0, 0, 0, 0, 1, 0};
	ACLR = (t_acceleration){0.05, 0.05};
	CTEXTURES = (t_map){0, 0};
	wolf_inject_textures(wolf);
}

char	*wolf_init_map(char *map)
{
	if (map[0] < '1' || map[0] > '3' || ft_strlen(map) != 1)
		exit(write(2,
			"There are only 3 levels yet so far. Use ./wolf3d [1-3]\n", 55));
	if (map[0] == '1')
		return (g_map1);
	else if (map[0] == '2')
		return (g_map2);
	else if (map[0] == '3')
		return (g_map3);
	else
		exit(write(2, "No such map dude\n", 17));
	return (0);
}

int		main(int argc, char **argv)
{
	t_wolf wolf;

	if (argc != 2)
		return ((int)write(2, "Right usage: ./wolf3d [1-3]\n", 28));
	wolf = (t_wolf){wolf_init_map(argv[1]), 0, argv,
		.mlx = {0}, .map_s = {0}, .key = {0}, .coords = {0},
		.textures = {{0}}, .draw = {0}};
	wolf_parse_map(&wolf);
	wolf_mlx_init(&wolf);
	mlx_hook(wolf.mlx.win, 17, 0L, wolf_exit, &wolf);
	mlx_hook(wolf.mlx.win, 2, (1L << 0), &wolf_key_press, &wolf);
	mlx_hook(wolf.mlx.win, 3, (1L << 1), &wolf_key_release, &wolf);
	wolf_data_init(&wolf);
	wolf_ray(&wolf);
	mlx_loop_hook(wolf.mlx.mlx, wolf_movement, &wolf);
	mlx_loop(wolf.mlx.mlx);
	return (0);
}
