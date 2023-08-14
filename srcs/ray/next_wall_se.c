/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_wall_se.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:20 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 20:48:54 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall_values	ft_init_values(t_real pos, float rad)
{
	t_wall_values	wall_values;

	wall_values.fct = ft_next_wall_se;
	wall_values.wall.door = false;
	wall_values.distance.y = (int)pos.y + 1 - pos.y;
	wall_values.distance.x = (int)pos.x + 1 - pos.x;
	wall_values.hypo.y = floor(
			1000000 * (wall_values.distance.y / sin(rad))) / 1000000;
	wall_values.hypo.x = floor(
			1000000 * (wall_values.distance.x / cos(rad))) / 1000000;
	return (wall_values);
}

static void	ft_case_1(float *rad, t_real *pos, t_wall_values *w)
{
	w->wall.pos.y = pos->y + (w->distance.y * tan(*rad));
	w->wall.pos.x = pos->x + (w->distance.x / tan(*rad));
	w->wall.direction = E_SOUTH;
}

static void	ft_case_2(float *rad, t_real *pos, t_wall_values *w)
{
	w->wall.pos.y = pos->y + w->distance.y;
	w->wall.pos.x = pos->x + (w->distance.y / tan(*rad));
	w->wall.direction = E_SOUTH;
}

static void	ft_case_3(float *rad, t_real *pos, t_wall_values *w)
{
	w->wall.pos.y = pos->y + (w->distance.x * tan(*rad));
	w->wall.pos.x = pos->x + w->distance.x;
	w->wall.direction = E_EAST;
}

t_wall	ft_next_wall_se(float rad, t_real pos, char **map)
{
	t_wall_values	w;

	w = ft_init_values(pos, rad);
	if (w.hypo.y == w.hypo.x)
	{
		ft_case_1(&rad, &pos, &w);
		w.wall = ft_mathias(map, &(t_real){(int)pos.x + 1, \
		(int)pos.y + 1}, &w, &rad);
	}
	else if (w.hypo.y < w.hypo.x)
	{
		ft_case_2(&rad, &pos, &w);
		w.wall = ft_mathias(map, &(t_real){(int)pos.x, \
		(int)pos.y + 1}, &w, &rad);
	}
	else
	{
		ft_case_3(&rad, &pos, &w);
		w.wall = ft_mathias(map, &(t_real){(int)pos.x + 1, \
		(int)pos.y}, &w, &rad);
	}
	return (w.wall);
}
