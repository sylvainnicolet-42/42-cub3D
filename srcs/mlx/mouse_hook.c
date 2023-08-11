/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:48:12 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:48:13 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse_hook(int x, int y, t_cube *cube)
{
	(void)y;
	if (cube->on_mouse == true)
	{
		if (x - cube->mouse_x > 0)
			ft_move_vision_right(cube, D_LOOK_MOUSE);
		else if (x - cube->mouse_x < 0)
			ft_move_vision_left(cube, D_LOOK_MOUSE);
	}
	cube->mouse_x = x;
	return (0);
}

int	ft_mouse_press(int button, int x, int y, t_cube *cube)
{
	if (button == E_MOUSE_LEFT)
	{
		if ((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HEIGHT))
		{
			cube->mouse_x = x;
			cube->on_mouse = true;
		}
	}
	return (0);
}

int	ft_mouse_release(int button, int x, int y, t_cube *cube)
{
	(void)x;
	(void)y;
	if (button == E_MOUSE_LEFT)
		cube->on_mouse = false;
	return (0);
}
