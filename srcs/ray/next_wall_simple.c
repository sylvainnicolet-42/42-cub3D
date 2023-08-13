/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wall_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:17 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:23:51 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_wall	ft_next_wall_e(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
	{
		if (map[(int)pos.y][(int)pos.x] == 'D')
		{
			wall.pos.y = pos.y;
			wall.pos.x = pos.x - (pos.x - (int)pos.x);
			wall.door = true;
			wall.direction = E_NORTH;
			return (wall);
		}
		pos.x++;
	}
	wall.pos.y = pos.y;
	wall.pos.x = pos.x - (pos.x - (int)pos.x);
	wall.door = false;
	wall.direction = E_NORTH;
	return (wall);
}

t_wall	ft_next_wall_s(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
	{
		if (map[(int)pos.y][(int)pos.x] == 'D')
		{
			wall.pos.y = pos.y - (pos.y - (int)pos.y);
			wall.pos.x = pos.x;
			wall.direction = E_WEST;
			wall.door = true;
			return (wall);
		}
		pos.y++;
	}
	wall.pos.y = pos.y - (pos.y - (int)pos.y);
	wall.pos.x = pos.x;
	wall.direction = E_WEST;
	wall.door = false;
	return (wall);
}

t_wall	ft_next_wall_w(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
	{
		if (map[(int)pos.y][(int)pos.x] == 'D')
		{
			wall.pos.y = pos.y;
			wall.pos.x = (int)pos.x + 1;
			wall.direction = E_SOUTH;
			wall.door = true;
			return (wall);
		}
		pos.x--;
	}
	wall.pos.y = pos.y;
	wall.pos.x = (int)pos.x + 1;
	wall.direction = E_SOUTH;
	wall.door = false;
	return (wall);
}

t_wall	ft_next_wall_n(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
	{
		if (map[(int)pos.y][(int)pos.x] == 'D')
		{
			wall.pos.y = (int)pos.y + 1;
			wall.pos.x = pos.x;
			wall.direction = E_EAST;
			wall.door = true;
			return (wall);
		}
		pos.y--;
	}
	wall.pos.y = (int)pos.y + 1;
	wall.pos.x = pos.x;
	wall.direction = E_EAST;
	wall.door = false;
	return (wall);
}
