/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:21:21 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:22:33 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_open_door(t_cube *cube)
{
	t_wall	wall;
	float	distance;

	wall = ft_get_wall(cube, cube->player->facing);
	distance = ft_get_distance(cube, wall, cube->player->facing);
	if (cube->player->facing > D_WEST - 0.000001 && \
		cube->player->facing < D_WEST + 0.000001)
		wall.pos.x -= 1;
	else if (cube->player->facing > D_NORTH - 0.000001 && \
		cube->player->facing < D_NORTH + 0.000001)
		wall.pos.y -= 1;
	if (wall.direction == E_WEST)
		wall.pos.x -= 1;
	else if (wall.direction == E_NORTH)
		wall.pos.y -= 1;
	if (wall.door == true)
	{
		if (distance < 1.15)
			cube->map[(int)wall.pos.y][(int)wall.pos.x] = '0';
	}
}
