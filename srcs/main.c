
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	ft_init_cube(ac, av, &cube);
	ft_free_all(&cube);
	return (0);
}
