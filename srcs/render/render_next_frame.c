
#include "cub3d.h"

static int	ft_get_pixel(t_img *img, int x, int y)
{
	int	color;

	x = (y * img->line_length) + (x * 4);
	color = ft_encode_rgb(img->addr[x], img->addr[x + 1], img->addr[x + 2]);
	return (color);
}

static void	print_texture(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while (x < cube->wall_e->width)
	{
		y = 0;
		while (y < cube->wall_e->height)
		{
			ft_mlx_pixel_put(cube->img, x, y, ft_get_pixel(cube->wall_e, x, y));
			y++;
		}
		x++;
	}
}

int	ft_render_next_frame(t_cube *cube)
{
	ft_floor_and_ceiling(cube);
	if (cube->scene == 2)
	{
		ft_minimap(cube);
		ft_print_player(cube);
	}
	ft_print_fov(cube);
	ft_print_wall(cube, cube->player->fov_start);
	print_texture(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}
