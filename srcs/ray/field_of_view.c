
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

	rad = ((2 * M_PI) / 360) * angle;
	return (rad);
}

void	ft_wall(t_cube *cube, float rad);

void	ft_print_fov(t_cube *cube)
{
	t_real	wall;
	int		angle;
	int		i;
	t_rgb	color;

	color.r = 0;
	color.g = 0;
	color.b = 255;
	angle = ft_rad_to_angle(cube->player->facing);
	angle -= 23;
	cube->player->fov_start = ft_angle_to_rad(angle);
	i = 0;
	while (i < 46)
	{
		if (angle < 0)
			angle += 360;
		else if (angle > 360)
			angle -= 360;
		wall = ft_get_wall(cube, angle, ft_angle_to_rad(angle));
		angle++;
		i++;
		ft_draw_line(cube, &wall, &color);
	}
	ft_wall(cube, cube->player->fov_start);
}

void	ft_draw_wall(t_cube *cube, float distance, int x, t_rgb *color)
{
	int		y;
	int		i;
	float	pouic;
	
	i = WIN_HEIGHT / 2;
	y = WIN_HEIGHT / 2;
	pouic = 1 / distance;
	if (pouic > 1)
		pouic = 1;
	while (y < ((WIN_HEIGHT * pouic) / 2) + (WIN_HEIGHT / 2))
	{
		ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(color->r, color->g, color->b));
		ft_mlx_pixel_put(cube->img, x, i, ft_encode_rgb(color->r, color->g, color->b));
		y++;
		i--;
	}
}

void	ft_wall(t_cube *cube, float rad)
{
	t_real	wall;
	t_rgb	color;
	int		x;
	float	a;
	float	b;
	float	distance;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	x = WIN_WIDTH / 2;
	while (x < WIN_WIDTH)
	{
		wall = ft_get_wall(cube, ft_rad_to_angle(rad), rad);
		rad += (ft_angle_to_rad(46)) / (WIN_WIDTH / 2);
		if (rad > M_PI * 2)
			rad -= M_PI * 2;
		a = wall.x - cube->player->pos_x;
		b = wall.y - cube->player->pos_y;
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		distance = sqrt(pow(a, 2) + pow(b, 2));
		if (distance < 0)
			distance *= -1;
		if (x == WIN_WIDTH / 2)
			printf("distance[%f]\n", distance);
		ft_draw_wall(cube, distance, x, &color);
		x++;
	}
}
