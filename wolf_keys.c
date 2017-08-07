/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 17:41:39 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/31 19:05:53 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			wolf_exit(void)
{
	exit(1);
	return (0);
}

int			wolf_key_press(int keycode, t_wolf *wolf)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 117)
		wolf_data_init(wolf);
	else if (keycode == 13 || keycode == 126)
		KEY.forward = 1;
	else if (keycode == 1 || keycode == 125)
		KEY.backwards = 1;
	else if (keycode == 0 || keycode == 123)
		KEY.left = 1;
	else if (keycode == 2 || keycode == 124)
		KEY.right = 1;
	else if (keycode == 257 || keycode == 258)
		ACLR.aclr = 0.1;
	else
	{
		if (keycode == 48)
			KEY.textures = (KEY.textures == 0) ? 1 : 0;
		else if (keycode == 4)
			KEY.hints = (KEY.hints == 0) ? 1 : 0;
	}
	return (0);
}

int			wolf_key_release(int keycode, t_wolf *wolf)
{
	if (keycode == 13 || keycode == 126)
		KEY.forward = 0;
	else if (keycode == 1 || keycode == 125)
		KEY.backwards = 0;
	else if (keycode == 0 || keycode == 123)
		KEY.left = 0;
	else if (keycode == 2 || keycode == 124)
		KEY.right = 0;
	else if (keycode == 257 || keycode == 258)
		ACLR.aclr = 0.05;
	return (0);
}

static void	wolf_sidestep(t_wolf *wolf)
{
	double direction;
	double plane;

	direction = DIRECTION.x;
	plane = PLANE.x;
	if (KEY.left)
	{
		DIRECTION.x =
		DIRECTION.x * cos(ACLR.r_aclr) - DIRECTION.y * sin(ACLR.r_aclr);
		DIRECTION.y =
		direction * sin(ACLR.r_aclr) + DIRECTION.y * cos(ACLR.r_aclr);
		PLANE.x = PLANE.x * cos(ACLR.r_aclr) - PLANE.y * sin(ACLR.r_aclr);
		PLANE.y = plane * sin(ACLR.r_aclr) + PLANE.y * cos(ACLR.r_aclr);
	}
	if (KEY.right)
	{
		DIRECTION.x =
		DIRECTION.x * cos(-ACLR.r_aclr) - DIRECTION.y * sin(-ACLR.r_aclr);
		DIRECTION.y =
		direction * sin(-ACLR.r_aclr) + DIRECTION.y * cos(-ACLR.r_aclr);
		PLANE.x = PLANE.x * cos(-ACLR.r_aclr) - PLANE.y * sin(-ACLR.r_aclr);
		PLANE.y = plane * sin(-ACLR.r_aclr) + PLANE.y * cos(-ACLR.r_aclr);
	}
}

int			wolf_movement(t_wolf *wolf)
{
	if (KEY.forward)
	{
		POS.x +=
		MAP_S.data[(int)(POS.x + DIRECTION.x * ACLR.aclr)][(int)POS.y] ?
		(double)0 : DIRECTION.x * ACLR.aclr;
		POS.y +=
		MAP_S.data[(int)POS.x][(int)(POS.y + DIRECTION.y * ACLR.aclr)] ?
		(double)0 : DIRECTION.y * ACLR.aclr;
	}
	if (KEY.backwards)
	{
		POS.x -=
		MAP_S.data[(int)(POS.x - DIRECTION.x * ACLR.aclr)][(int)POS.y] ?
		(double)0 : DIRECTION.x * ACLR.aclr;
		POS.y -=
		MAP_S.data[(int)POS.x][(int)(POS.y - DIRECTION.y * ACLR.aclr)] ?
		(double)0 : DIRECTION.y * ACLR.aclr;
	}
	wolf_sidestep(wolf);
	wolf_ray(wolf);
	return (KEY.hints ? wolf_show_hints(wolf) : 0);
}
