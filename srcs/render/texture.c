/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:04 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:15:18 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_get_img(t_wall wall, t_cube *cube)
{
	if (wall.door == true)
		return (cube->door);
	if (wall.direction == E_NORTH)
		return (cube->wall_n);
	else if (wall.direction == E_WEST)
		return (cube->wall_w);
	else if (wall.direction == E_SOUTH)
		return (cube->wall_s);
	else if (wall.direction == E_EAST)
		return (cube->wall_e);
	return (0);
}
