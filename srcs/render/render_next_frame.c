
#include "cub3d.h"

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
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}
