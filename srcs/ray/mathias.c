/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathias.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:42:05 by synicole          #+#    #+#             */
/*   Updated: 2023/08/14 14:10:44 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_wall	ft_mathias(char **map, t_real *pos, t_wall_values *w, const float *rad)
{
	if (pos->y < w->cube->map_max_y)
	{
		if(pos->x < w->cube->map_max_x)
		{	
			if (map[(int)pos->y][(int)pos->x] == 'D')
				w->wall.door = true;
			else if (map[(int)pos->y][(int)pos->x] != '1')
				w->wall = w->fct(*rad, w->wall.pos, map, w->cube);
		}
		else
		{
			w->wall.pos.x = w->cube->map_max_x - 1;
			printf("x[%f]\n", pos->x);
		}
	}
	else
	{
		w->wall.pos.y = w->cube->map_max_y - 1;
		printf("y[%f]\n", pos->y);
	}
	return (w->wall);
}
