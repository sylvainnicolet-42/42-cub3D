
#include "cub3d.h"

void	ft_init_cube(int ac, char **av, t_cube *cube)
{
	t_matrice	*matrice;

	ft_check_arguments(ac, av);
	*cube = (t_cube) {};
	matrice = malloc(sizeof(t_matrice));
	*matrice = (t_matrice) {};
	cube->matrice = matrice;
}
