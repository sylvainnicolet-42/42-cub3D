
#include "cub3d.h"

/**
 * Initialize the struct t_cube.
 * @param matrix
 * @return
 */
t_cube	*ft_init_cube(t_matrix *matrix)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	if (!cube)
		ft_print_error(MSG_MALLOC_ERR);
	*cube = (t_cube){};
	cube->matrix = matrix;
	ft_init_mlx(cube);
	return (cube);
}
