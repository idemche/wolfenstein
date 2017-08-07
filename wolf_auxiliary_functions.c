/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_auxiliary_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 01:55:07 by idemche           #+#    #+#             */
/*   Updated: 2017/07/31 19:05:40 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_bool	wolf_free_map(char **map)
{
	char **head;

	head = map;
	while (map && *map)
		free(*map++);
	free(head);
	return (0);
}

t_bool	wolf_free_data(int **data, int size)
{
	int cleaner;

	cleaner = -1;
	while (data && data[++cleaner] && cleaner < size)
		free(data[cleaner]);
	free(data);
	return (0);
}

int		wolf_atoi(char *str)
{
	char	sign;
	long	nbr;

	sign = 1;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? (char)-1 : (char)1;
	if (NOTADIGIT(*str))
		return (-1);
	nbr = 0;
	while (*str >= 48 && *str <= 57)
		(nbr = nbr * 10 + *str++ - 48);
	if ((*str && NOTADIGIT(*str)) ||
		!(sign * nbr <= 2147483647 && sign * nbr >= -2147483648))
		return (-1);
	return ((int)(sign * nbr));
}

short	wolf_map_size(t_wolf *wolf)
{
	char	**map;
	short	size;

	size = 0;
	map = MAP_S.map;
	while (*map)
	{
		if (!size)
		{
			MAP_S.linelen = (int)ft_strlen(*map);
			MAP_S.elements = ft_word_count(*map, ' ');
		}
		if (size++ > 100 || ft_strlen(*map) > 500)
			exit((int)write(2, "Map is too big!\n", 16));
		map++;
	}
	return (size);
}

int		wolf_show_hints(t_wolf *wolf)
{
	mlx_string_put(MLX.mlx, MLX.win, 10, 10,
		!KEY.textures ? 0x0 : 15658734, "WASD <-ARROWS-> TO MOVE");
	mlx_string_put(MLX.mlx, MLX.win, 10, 30,
		!KEY.textures ? 0x0 : 15658734, "SHIFT TO MOVE FASTER");
	mlx_string_put(MLX.mlx, MLX.win, 10, 50,
		!KEY.textures ? 0x0 : 15658734, "DELETE TO RESET");
	mlx_string_put(MLX.mlx, MLX.win, 10, 70,
		!KEY.textures ? 0x0 : 15658734, "TAB TO SHOW TEXTURES");
	mlx_string_put(MLX.mlx, MLX.win, 10, 90,
		!KEY.textures ? 0x0 : 15658734, "H TO SHOW HINTS");
	mlx_string_put(MLX.mlx, MLX.win, 10, 110,
		!KEY.textures ? 0x0 : 15658734, "ESC OR RED CROSS TO QUIT");
	return (0);
}
