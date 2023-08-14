/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wall_ne.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:27 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 20:46:50 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall_values	ft_init_values(t_real pos, float rad)
{
	t_wall_values	wall_val;

	wall_val.fct = ft_next_wall_ne;
	wall_val.of7.y = 0;
	wall_val.dir = (2 * M_PI) - rad;
	wall_val.wall.door = false;
	wall_val.distance.y = pos.y - (int)pos.y;
	wall_val.distance.x = (int)pos.x + 1 - pos.x;
	if (wall_val.distance.y == 0)
	{
		wall_val.of7.y = 1;
		wall_val.distance.y = 1;
	}
	wall_val.hypo.y = floor(
			1000000 * (wall_val.distance.y / sin(wall_val.dir))) / 1000000;
	wall_val.hypo.x = floor(
			1000000 * (wall_val.distance.x / cos(wall_val.dir))) / 1000000;
	return (wall_val);
}

static void	ft_case_1(t_wall_values *w, t_real *pos)
{
	w->wall.pos.y = pos->y - (w->distance.y * tan(w->dir));
	w->wall.pos.x = pos->x + (w->distance.x / tan(w->dir));
	w->wall.direction = E_NORTH;
}

static void	ft_case_2(t_wall_values *w, t_real *pos)
{
	w->wall.pos.y = pos->y - w->distance.y;
	w->wall.pos.x = pos->x + (w->distance.y / tan(w->dir));
	w->wall.direction = E_NORTH;
}

static void	ft_case_3(t_wall_values *w, t_real *pos)
{
	w->wall.pos.y = pos->y - (w->distance.x * tan(w->dir));
	w->wall.pos.x = pos->x + w->distance.x;
	w->wall.direction = E_EAST;
}

t_wall	ft_next_wall_ne(float rad, t_real pos, char **map)
{
	t_wall_values	w;

	w = ft_init_values(pos, rad);
	if (w.hypo.y == w.hypo.x)
	{
		ft_case_1(&w, &pos);
		w.wall = ft_mathias(map, &(t_real){(int)pos.x + 1, \
		(int)(pos.y - 1 - w.of7.y)}, &w, &rad);
	}
	else if (w.hypo.y < w.hypo.x)
	{
		ft_case_2(&w, &pos);
		w.wall = ft_mathias(map, &(t_real){(int)pos.x, \
		(int)(pos.y - 1 - w.of7.y)}, &w, &rad);
	}
	else
	{
		ft_case_3(&w, &pos);
		w.wall = ft_mathias(map, &(t_real){(int)pos.x + 1, \
		(int)(pos.y - w.of7.y)}, &w, &rad);
	}
	return (w.wall);
}
