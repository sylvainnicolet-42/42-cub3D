
#include "cub3d.h"

int	ft_render_next_frame(t_cube *cube)
{
	ft_floor_and_ceiling(cube);
	ft_minimap(cube);
//	ft_print_ray(cube, cube->player->facing);
	ft_print_fov(cube);
	ft_print_player(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}
