
#include "cub3d.h"

/**
 * Close the program
 * @param cube
 *
 * @return int
 */
int	ft_close(t_cube *cube)
{
//	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	free(cube->matrix);
	free(cube);
	ft_print_success(MSG_CLOSE_SUCCESS);
	return (0);
}
