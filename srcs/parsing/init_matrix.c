
#include "cub3d.h"

/**
 * Initialize the matrix.
 *
 * @param ac
 * @param av
 *
 * @return t_matrix*
 */
t_matrix	*ft_init_matrix(int ac, char **av)
{
	t_matrix	*matrix;

	ft_check_arguments(ac, av);
	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
		ft_print_error(MSG_MALLOC_ERR);
	*matrix = (t_matrix){};
	return (matrix);
}
