
#include "cub3d.h"

static int	ft_direction(int direction)
{
	if (direction == E_NORTH)
		return (ft_encode_rgb(204, 0, 0));
	else if (direction == E_WEST)
		return (ft_encode_rgb(250, 172, 172));
	else if (direction == E_SOUTH)
		return (ft_encode_rgb(0, 204, 0));
	else if (direction == E_EAST)
		return (ft_encode_rgb(172, 250, 172));
	return (0);
}

static void	ft_draw_wall(t_cube *cube, float distance, int x, int direction)
{
	int		y;
	int		i;
	int		color;

	i = WIN_HEIGHT / 2;
	y = WIN_HEIGHT / 2;
	distance = 1 / distance;
	if (distance > 1)
		distance = 1;
	while (y < ((WIN_HEIGHT * distance) / 2) + (WIN_HEIGHT / 2))
	{
		color = ft_direction(direction);
		ft_mlx_pixel_put(cube->img, x, y, color);
		ft_mlx_pixel_put(cube->img, x, i, color);
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

static void	ft_print_direction(int direction)
{
	if (direction == E_NORTH)
		printf("Looking Norh\n");
	if (direction == E_SOUTH)
		printf("Looking South\n");
	if (direction == E_EAST)
		printf("Looking East\n");
	if (direction == E_WEST)
		printf("Looking West\n");
}

void	ft_print_wall(t_cube *cube, float rad)
{
	t_wall	wall;
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
		pyth.x = cube->player->real->x - wall.pos.x;
		pyth.y = cube->player->real->y - wall.pos.y;
		if (pyth.x < 0)
			pyth.x *= -1;
		if (pyth.y < 0)
			pyth.y *= -1;
		distance = ft_get_distance(cube, pyth, rad);
		if (cube->scene == 1 || cube->scene == 3)
		{
			if (x == WIN_WIDTH / 2)
				ft_print_direction(wall.direction);
		}
		else
		{
			if (x == (WIN_WIDTH / 2) + (WIN_WIDTH / 4))
				ft_print_direction(wall.direction);
		}
		ft_draw_wall(cube, distance, x, wall.direction);
		x++;
	}
}
