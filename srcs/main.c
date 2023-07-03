
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cube		*cube;

	cube = ft_init_cube(ac, av);
	db_print_cube(cube);
	ft_handle_event(cube);
	ft_start(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
