/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wall_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:17 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:44:18 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_wall	ft_next_wall_e(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.x++;
	wall.pos.y = pos.y;
	wall.pos.x = pos.x - (pos.x - (int)pos.x);
	wall.direction = E_NORTH;
	return (wall);
}

t_wall	ft_next_wall_s(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.y++;
	wall.pos.y = pos.y - (pos.y - (int)pos.y);
	wall.pos.x = pos.x;
	wall.direction = E_WEST;
	return (wall);
}

t_wall	ft_next_wall_w(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.x--;
	wall.pos.y = pos.y;
	wall.pos.x = (int)pos.x + 1;
	wall.direction = E_SOUTH;
	return (wall);
}

t_wall	ft_next_wall_n(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.y--;
	wall.pos.y = (int)pos.y + 1;
	wall.pos.x = pos.x;
	wall.direction = E_EAST;
	return (wall);
}
