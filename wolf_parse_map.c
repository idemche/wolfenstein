/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_parse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 00:54:28 by idemche           #+#    #+#             */
/*   Updated: 2017/07/31 19:05:56 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_bool			wolf_validate_map(t_wolf *wolf)
{
	int x;
	int y;

	x = -1;
	while (MAP_S.map && MAP_S.map[++x] && *MAP_S.map[x])
	{
		y = -1;
		while (MAP_S.map[x][++y])
			if (NOTADIGIT(MAP_S.map[x][y]) && !SPACER(MAP_S.map[x][y]))
				return (0);
		if (ft_strlen_limit(MAP_S.map[x], '\n') != (size_t)MAP_S.linelen)
			return (0);
	}
	return (1);
}

static	t_bool			wolf_parse_data(t_wolf *wolf)
{
	char	**parse_digit;
	int		x;
	int		y;

	x = -1;
	MAP_S.data = NEW(int**, MAP_S.size);
	MAP_S.size = 0;
	while (MAP_S.map[++x] && MAP_S.map[x][0])
	{
		y = -1;
		if ((parse_digit = ft_strsplit(MAP_S.map[x], ' ')))
		{
			MAP_S.data[x] = NEW(int*, MAP_S.elements);
			MAP_S.size++;
		}
		while (parse_digit[++y])
			if ((MAP_S.data[x][y] =
				wolf_atoi(parse_digit[y])) > 4 || MAP_S.data[x][y] < 0)
				return (0);
		if (parse_digit)
			wolf_free_map(parse_digit);
	}
	return (1);
}

static t_bool			wolf_check_sides(t_wolf *wolf)
{
	int x;

	x = -1;
	if (!MAP_S.data || MAP_S.size < 3 || MAP_S.elements < 3)
		return (0);
	while (++x < MAP_S.elements)
		if (MAP_S.data && *MAP_S.data
			&& (MAP_S.data[0][x] == 0 || MAP_S.data[MAP_S.size - 1][x] == 0))
			return (0);
	x = -1;
	while (++x < MAP_S.size)
		if (MAP_S.data[x][0] == 0 || MAP_S.data[x][MAP_S.elements - 1] == 0)
			return (0);
	if (MAP_S.data[MAP_S.size / 2]
		&& MAP_S.data[MAP_S.size / 2][MAP_S.elements / 2] != 0)
		return (0);
	return (1);
}

void					wolf_parse_map(t_wolf *wolf)
{
	MAP_S.map = ft_strsplit(wolf->level, '\n');
	MAP_S.size = wolf_map_size(wolf);
	if (!wolf_validate_map(wolf))
	{
		wolf_free_map(MAP_S.map);
		exit((int)write(2, "I cant process this map. Try another\n", 37));
	}
	else if (!wolf_parse_data(wolf) || !wolf_check_sides(wolf))
	{
		wolf_free_map(MAP_S.map);
		wolf_free_data(MAP_S.data, MAP_S.size);
		exit((int)write(2, "I cant process this map. Try another\n", 37));
	}
}
