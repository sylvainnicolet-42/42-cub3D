
#include "cub3d.h"

/**
 * Initialize the struct t_cube.
 * @param matrice
 * @return
 */
t_cube	*ft_init_cube(t_matrice *matrice)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
		ft_print_error(MSG_MALLOC_ERR);
	*cube = (t_cube){};
	cube->matrice = matrice;
	ft_init_mlx(cube);
	return (cube);
}
