/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wall_nw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:24 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/14 13:36:40 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall_values	ft_init_values(t_real pos, float rad, t_cube *cube)
{
	t_wall_values	wall_val;

	wall_val.cube = cube;
	wall_val.fct = ft_next_wall_nw;
	wall_val.of7.y = 0;
	wall_val.of7.x = 0;
	wall_val.dir = rad - M_PI;
	wall_val.wall.door = false;
	wall_val.distance.y = pos.y - (int)pos.y;
	wall_val.distance.x = pos.x - (int)pos.x;
	if (wall_val.distance.y == 0)
	{
		wall_val.of7.y = 1;
		wall_val.distance.y = 1;
	}
	if (wall_val.distance.x == 0)
	{
		wall_val.of7.x = 1;
		wall_val.distance.x = 1;
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
	w->wall.pos.x = pos->x - (w->distance.y / tan(w->dir));
	w->wall.direction = E_NORTH;
}

static void	ft_case_2(t_wall_values *w, t_real *pos)
{
	w->wall.pos.y = pos->y - w->distance.y;
	w->wall.pos.x = pos->x - (w->distance.y / tan(w->dir));
	w->wall.direction = E_NORTH;
}

static void	ft_case_3(t_wall_values *w, t_real *pos)
{
	w->wall.pos.y = pos->y - (w->distance.x * tan(w->dir));
	w->wall.pos.x = pos->x - w->distance.x;
	w->wall.direction = E_WEST;
}

t_wall	ft_next_wall_nw(float rad, t_real pos, char **map, t_cube *cube)
{
	t_wall_values	w;

	w = ft_init_values(pos, rad, cube);
	if (w.hypo.y == w.hypo.x)
	{
		ft_case_1(&w, &pos);
		w.wall = ft_mathias(map, &(t_real){(int)(pos.x - 1 - w.of7.x), \
		(int)(pos.y - 1 - w.of7.y)}, &w, &rad);
	}
	else if (w.hypo.y < w.hypo.x)
	{
		ft_case_2(&w, &pos);
		w.wall = ft_mathias(map, &(t_real){(int)(pos.x - w.of7.x), \
		(int)(pos.y - 1 - w.of7.y)}, &w, &rad);
	}
	else
	{
		ft_case_3(&w, &pos);
		w.wall = ft_mathias(map, &(t_real){(int)(pos.x - 1 - w.of7.x), \
		(int)(pos.y - w.of7.y)}, &w, &rad);
	}
	return (w.wall);
}
