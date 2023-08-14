/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_vision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:48:48 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/14 13:00:51 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_vision_left(t_cube *cube, int look)
{
//	printf("Look Left\n");
	cube->player->facing -= ((M_PI * 2) / 360) * look;
	cube->player->facing = floor(1000000 * cube->player->facing) / 1000000;
	if (cube->player->facing < 0)
		cube->player->facing += (M_PI * 2);
//	printf("Player facing [%f]\n", cube->player->facing);
}

void	ft_move_vision_right(t_cube *cube, int look)
{
//	printf("Look Right\n");
	cube->player->facing += ((M_PI * 2) / 360) * look;
	cube->player->facing = floor(1000000 * cube->player->facing) / 1000000;
	if (cube->player->facing > M_PI * 2)
		cube->player->facing -= (M_PI * 2);
//	printf("Player facing [%f]\n", cube->player->facing);
}
