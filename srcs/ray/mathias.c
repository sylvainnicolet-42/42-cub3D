/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathias.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:42:05 by synicole          #+#    #+#             */
/*   Updated: 2023/08/14 10:42:10 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_wall	ft_mathias(char **map, t_real *pos, t_wall_values *w, const float *rad)
{
	if (map[(int)pos->y] != NULL)
	{
		if (map[(int)pos->y][(int)pos->x] == 'D')
			w->wall.door = true;
		else if (map[(int)pos->y][(int)pos->x] != '1')
			w->wall = w->fct(*rad, w->wall.pos, map);
	}
	return (w->wall);
}
