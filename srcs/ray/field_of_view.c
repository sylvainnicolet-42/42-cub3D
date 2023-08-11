/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_of_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:37 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:44:39 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_rad_to_angle(float facing)
{
	int	angle;

	angle = (int)((360 / (2 * M_PI)) * facing);
	return (angle);
}

float	ft_angle_to_rad(int angle)
{
	float	rad;

	rad = floor(1000000 * ((2 * M_PI) / 360) * angle) / 1000000;
	return (rad);
}

void	ft_print_fov(t_cube *cube)
{
	t_wall	wall;
	int		angle;
	int		i;

	angle = ft_rad_to_angle(cube->player->facing);
	angle -= D_FOV / 2;
	if (angle < 0)
		angle += 360;
	cube->player->fov_start = ft_angle_to_rad(angle);
	i = 0;
	while (i < D_FOV)
	{
		if (angle < 0)
			angle += 360;
		else if (angle > 360)
			angle -= 360;
		wall = ft_get_wall(cube, ft_angle_to_rad(angle));
		angle++;
		i++;
		if (cube->scene == 2)
			ft_draw_line(cube, &wall.pos, &(t_rgb){0, 0, 255});
	}
}
