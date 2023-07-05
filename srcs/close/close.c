
#include "cub3d.h"

/**
 * Close the program
 * @param cube
 *
 * @return int
 */
static void	ft_free_cube(t_cube *cube)
{
	free(cube->path_wall_n);
	free(cube->path_wall_s);
	free(cube->path_wall_w);
	free(cube->path_wall_e);
	free(cube->f);
	free(cube->c);
	ft_free_array(cube->map);
	free(cube->player);
	free(cube->img);
	free(cube);
}

int	ft_close(t_cube *cube)
{
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	ft_free_cube(cube);
	ft_print_success(MSG_CLOSE_SUCCESS);
	return (0);
}
