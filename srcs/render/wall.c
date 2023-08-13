/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:44:08 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:15:46 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_real	ft_get_pos(t_wall wall, int y, int height, t_img *img)
{
	t_real	pos;

	pos.x = 0;
	pos.y = 0;
	if (wall.direction == E_NORTH || wall.direction == E_SOUTH)
		pos.x = (wall.pos.x - (int)wall.pos.x) * img->width;
	else
		pos.x = (wall.pos.y - (int)wall.pos.y) * img->width;
	y = y - ((WIN_HEIGHT / 2) - (height / 2));
	pos.y = ((float)img->height / (float)height) * y;
	return (pos);
}

static void	ft_draw_wall(t_cube *cube, float distance, int x, t_wall wall)
{
	int		y;
	t_real	pos;
	t_img	*img;
	int		pixel;

	y = WIN_HEIGHT / 2;
	distance = 1 / distance;
	if (distance > 1)
		distance = 1;
	y = ((WIN_HEIGHT * distance) / 2) + (WIN_HEIGHT / 2);
	while (y > (WIN_HEIGHT - (WIN_HEIGHT * distance)) / 2)
	{
		img = ft_get_img(wall, cube);
		pos = ft_get_pos(wall, y, WIN_HEIGHT * distance, img);
		pixel = (((int)pos.x * (int)img->width) + (int)pos.y);
		if (x < WIN_WIDTH && x >= 0 && y < WIN_HEIGHT && y >= 0 && pixel >= 0
			&& pixel < img->width * img->height)
			ft_mlx_pixel_put(cube->img, x, y, img->color[pixel]);
		y--;
	}
}

static void	ft_init_values(int *x, int *end, t_cube *cube)
{
	*x = 0;
	*end = WIN_WIDTH;
	if (cube->scene == 2)
	{
		*x = WIN_WIDTH / 2;
		*end = *x;
	}
}

float	ft_get_distance(t_cube *cube, t_wall wall, float rad)
{
	float	distance;
	t_real	pyth;

	pyth.x = cube->player->real->x - wall.pos.x;
	pyth.y = cube->player->real->y - wall.pos.y;
	if (pyth.x < 0)
		pyth.x *= -1;
	if (pyth.y < 0)
		pyth.y *= -1;
	distance = sqrt((pyth.x * pyth.x) + (pyth.y * pyth.y));
	if (cube->scene == 3)
	{
		if (distance < 0)
			distance *= -1;
		return (distance);
	}
	distance *= cos(cube->player->facing - rad);
	if (distance < 0)
		distance *= -1;
	return (distance);
}

void	ft_print_wall(t_cube *cube, float rad)
{
	t_wall	wall;
	int		x;
	int		end;
	float	distance;

	ft_init_values(&x, &end, cube);
	while (x < WIN_WIDTH)
	{
		wall = ft_get_wall(cube, rad);
		rad += (ft_angle_to_rad(D_FOV)) / (float)end;
		rad = floor(1000000 * rad) / 1000000;
		if (rad > M_PI * 2)
			rad -= M_PI * 2;
		distance = ft_get_distance(cube, wall, rad);
		ft_draw_wall(cube, distance, x, wall);
		x++;
	}
}
