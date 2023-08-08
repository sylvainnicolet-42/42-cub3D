
#include "cub3d.h"

static int	ft_get_pixel(t_img *img, int x, int y, int line_length)
{
	int	color;

	x = (y * line_length) + (x * 4);
	color = ft_encode_rgb(img->addr[x], img->addr[x + 1], img->addr[x + 2]);
	return (color);
}

static int	ft_get_texture(t_cube *cube, int x, int y)
{
	t_img	*img;
	t_real	scale;
	int		x_texture;
	int		y_texture;
	int		color;

	img = malloc(sizeof(t_img));
	img->img = mlx_xpm_file_to_image(cube->mlx_ptr, cube->path_wall_n, &x_texture, &y_texture);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,&img->line_length, &img->endian);
	scale.x = (float)WIN_WIDTH / (img->line_length / 4);
	scale.y = (float)WIN_HEIGHT / (img->line_length / 4);
	color = ft_get_pixel(img, x / scale.x, y / scale.y, img->line_length);
	free(img);
	return (color);
}

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
		ft_mlx_pixel_put(cube->img, x, y, ft_get_texture(cube, x, y));
		ft_mlx_pixel_put(cube->img, x, i, ft_get_texture(cube,x ,y));
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
