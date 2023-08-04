
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

void	ft_draw_wall(t_cube *cube, float distance, int x)
{
	int		y;
	int		i;
	
	i = WIN_HEIGHT / 2;
	y = WIN_HEIGHT / 2;
	distance = 1 / distance;
	if (distance > 1)
		distance = 1;
	while (y < ((WIN_HEIGHT * distance) / 2) + (WIN_HEIGHT / 2))
	{
		ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(255, 255, 255));
		ft_mlx_pixel_put(cube->img, x, i, ft_encode_rgb(255, 255, 255));
		y++;
		i--;
	}
}

void	ft_wall(t_cube *cube, float rad)
{
	t_real	wall;
	int		x;
	float	a;
	float	b;
	float	distance;

	x = WIN_WIDTH / 2;
	while (x < WIN_WIDTH)
	{
		wall = ft_get_wall(cube, ft_rad_to_angle(rad), rad);
		rad += (ft_angle_to_rad(46)) / (WIN_WIDTH / 2);
		if (rad > M_PI * 2)
			rad -= M_PI * 2;
		a = cube->player->real->x - wall.x;
		b = cube->player->real->y - wall.y;
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		distance = sqrt((a * a) + (b * b));
		if (distance < 0)
			distance *= -1;
		if (x == WIN_WIDTH / 2)
			printf("distance[%f] a[%f] b[%f]\n", distance, a, b);
		ft_draw_wall(cube, distance, x);
		x++;
	}
}
