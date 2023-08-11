/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:43:54 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:43:56 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_print_direction(t_cube *cube)
{
	double	x_p;
	double	y_p;
	t_real	real;

	x_p = cos(cube->player->facing) * 0.2f;
	y_p = sin(cube->player->facing) * 0.2f;
	real.x = cube->player->real->x + x_p;
	real.y = cube->player->real->y + y_p;
	ft_draw_cube(cube, &real, 0.05, &(t_rgb){255, 0, 252});
}

void	ft_print_player(t_cube *cube)
{
	ft_draw_cube(cube, cube->player->real, D_PLAYER_SCALE, cube->player->color);
	ft_print_direction(cube);
}

void	ft_draw_cube(t_cube *cube, t_real *real, float size, t_rgb *rgb)
{
	float	ratio_x;
	float	ratio_y;
	float	x;
	float	y;

	ratio_x = ((float)WIN_WIDTH / 2) / cube->map_max_x;
	ratio_y = (float)WIN_HEIGHT / cube->map_max_y;
	x = (real->x - size / 2) * ratio_x;
	y = (real->y - size / 2) * ratio_y;
	while (y < (real->y + size / 2) * ratio_y)
	{
		while (x < (real->x + size / 2) * ratio_x)
		{
			ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(
					rgb->r, rgb->g, rgb->b));
			x++;
		}
		x = (real->x - size / 2) * ratio_x;
		y++;
	}
}
