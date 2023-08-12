/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:48:15 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/12 04:54:27 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Apply the key
 * @param key
 * @param cube
 *
 * @return void
 */

int	ft_key_hook_linux(int key, t_cube *cube)
{
	if (key == E_KEY_LINUX_W)
		ft_move_forward(cube);
	else if (key == E_KEY_LINUX_S)
		ft_move_backward(cube);
	else if (key == E_KEY_LINUX_A)
		ft_move_left(cube);
	else if (key == E_KEY_LINUX_D)
		ft_move_right(cube);
	else if (key == E_KEY_LINUX_E)
		ft_open_door(cube);
	else if (key == E_KEY_LINUX_ARROW_LEFT)
		ft_move_vision_left(cube, D_LOOK_ARROW);
	else if (key == E_KEY_LINUX_ARROW_RIGHT)
		ft_move_vision_right(cube, D_LOOK_ARROW);
	else if (key == E_KEY_LINUX_ESC)
		ft_close(cube);
	else if (key == E_KEY_LINUX_1)
		cube->scene = 1;
	else if (key == E_KEY_LINUX_2)
		cube->scene = 2;
	else if (key == E_KEY_LINUX_3)
		cube->scene = 3;
	return (0);
}

/**
 * Handle key events
 * @param key
 * @param cube
 * @return
 */
int	ft_key_hook(int key, t_cube *cube)
{
	if (key == E_KEY_W)
		ft_move_forward(cube);
	else if (key == E_KEY_S)
		ft_move_backward(cube);
	else if (key == E_KEY_A)
		ft_move_left(cube);
	else if (key == E_KEY_D)
		ft_move_right(cube);
	else if (key == E_KEY_ARROW_LEFT)
		ft_move_vision_left(cube, D_LOOK_ARROW);
	else if (key == E_KEY_ARROW_RIGHT)
		ft_move_vision_right(cube, D_LOOK_ARROW);
	else if (key == E_KEY_ESC)
		ft_close(cube);
	else if (key == E_KEY_1)
		cube->scene = 1;
	else if (key == E_KEY_2)
		cube->scene = 2;
	else if (key == E_KEY_3)
		cube->scene = 3;
	return (0);
}
