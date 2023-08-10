
#include "cub3d.h"

/*static void	ft_print_texture(t_cube *cube)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (x < cube->wall_w->width)
	{
		y = 0;
		while (y < cube->wall_w->height)
		{
			i = (x * 176) + y;
			ft_mlx_pixel_put(cube->img, x, y, cube->wall_w->color[i]);
			y++;
		}
		x++;
	}
}*/

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
//	ft_print_texture(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}
