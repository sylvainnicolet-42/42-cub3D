
#include "cub3d.h"

int ft_render_next_frame(t_cube *cube)
{
//	ft_floor_and_ceiling(cube);
//	ft_wall(cube);
//	ft_minimap(cube);
	ft_map_2d(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}
