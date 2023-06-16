
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_matrice	*matrice;
	t_cube		*cube;

	matrice = ft_init_matrice(ac, av);
	cube = ft_init_cube(matrice);
	// ft_execution()
	ft_handle_event(cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
