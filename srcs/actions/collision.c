/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:48:43 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:21:14 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_m_i_in_wall(char **map, float x, float y, float sc)
{
	if (map[(int)(y + sc)][(int)(x + sc)] == '1')
		return (false);
	if (map[(int)(y - sc)][(int)(x - sc)] == '1')
		return (false);
	if (map[(int)(y + sc)][(int)(x - sc)] == '1')
		return (false);
	if (map[(int)(y - sc)][(int)(x + sc)] == '1')
		return (false);
	if (map[(int)(y + sc)][(int)(x + sc)] == 'D')
		return (false);
	if (map[(int)(y - sc)][(int)(x - sc)] == 'D')
		return (false);
	if (map[(int)(y + sc)][(int)(x - sc)] == 'D')
		return (false);
	if (map[(int)(y - sc)][(int)(x + sc)] == 'D')
		return (false);
	return (true);
}

bool	ft_collision_forw(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_x += real->x;
	d_y += real->y;
	if (ft_m_i_in_wall(map, d_x, d_y, sc) == false)
		return (false);
	return (true);
}

bool	ft_collision_back(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_x = real->x - d_x;
	d_y = real->y - d_y;
	if (ft_m_i_in_wall(map, d_x, d_y, sc) == false)
		return (false);
	return (true);
}

bool	ft_collision_left(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_y += real->x;
	d_x = real->y - d_x;
	if (ft_m_i_in_wall(map, d_y, d_x, sc) == false)
		return (false);
	return (true);
}

bool	ft_collision_right(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_y = real->x - d_y;
	d_x += real->y;
	if (ft_m_i_in_wall(map, d_y, d_x, sc) == false)
		return (false);
	return (true);
}
