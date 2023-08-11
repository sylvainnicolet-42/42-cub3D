/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:04 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:44:05 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_get_img(int direction, t_cube *cube)
{
	if (direction == E_NORTH)
		return (cube->wall_n);
	else if (direction == E_WEST)
		return (cube->wall_w);
	else if (direction == E_SOUTH)
		return (cube->wall_s);
	else if (direction == E_EAST)
		return (cube->wall_e);
	return (0);
}
