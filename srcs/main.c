
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cube		*cube;

	cube = ft_init_cube(ac, av);
	db_print_cube(cube);
//	ft_execution()
//	ft_handle_event(cube);
//	mlx_loop(cube->mlx_ptr);
	ft_close(cube);
	return (0);
}
