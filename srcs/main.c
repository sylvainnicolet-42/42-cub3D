
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cube		*cube;

	cube = ft_init_cube(ac, av);
	db_print_cube(cube);
	ft_handle_event(cube);
	ft_render_next_frame(cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
