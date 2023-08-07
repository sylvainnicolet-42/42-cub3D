
#include "cub3d.h"

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
		rad += (ft_angle_to_rad(D_FOV)) / (WIN_WIDTH / 2);
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
		if (x == (WIN_WIDTH / 2) + (WIN_WIDTH / 4))
			printf("distance[%f]\n", distance);
		ft_draw_wall(cube, distance, x);
		x++;
	}
}
