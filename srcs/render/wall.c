
#include "cub3d.h"

static void	ft_draw_wall(t_cube *cube, float distance, int x)
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

static float	ft_get_distance(t_cube *cube, t_real pyth, float rad)
{
	float	distance;

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
	t_real	wall;
	int		x;
	int		end;
	t_real	pyth;
	float	distance;

	ft_init_values(&x, &end, cube);
	while (x < WIN_WIDTH)
	{
		wall = ft_get_wall(cube, ft_rad_to_angle(rad), rad);
		rad += (ft_angle_to_rad(D_FOV)) / (float)end;
		if (rad > M_PI * 2)
			rad -= M_PI * 2;
		pyth.x = cube->player->real->x - wall.x;
		pyth.y = cube->player->real->y - wall.y;
		if (pyth.x < 0)
			pyth.x *= -1;
		if (pyth.y < 0)
			pyth.y *= -1;
		distance = ft_get_distance(cube, pyth, rad);
		ft_draw_wall(cube, distance, x);
		x++;
	}
}
