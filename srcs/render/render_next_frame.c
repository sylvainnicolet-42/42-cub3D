
#include "cub3d.h"

int	ft_render_next_frame(t_cube *cube)
{
	ft_floor_and_ceiling(cube);
//	ft_wall(cube);
//	ft_minimap(cube);
	ft_map_2d(cube);
	ft_print_player(cube);
	//ft_print_ray(cube, cube->player->facing);
	//ft_print_ray_v2(cube, cube->player->facing);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}
