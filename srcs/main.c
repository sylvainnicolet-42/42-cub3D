
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_matrix	*matrix;
	t_cube		*cube;

	matrix = ft_init_matrix(ac, av);
	cube = ft_init_cube(matrix);
	// ft_execution()
	ft_handle_event(cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
