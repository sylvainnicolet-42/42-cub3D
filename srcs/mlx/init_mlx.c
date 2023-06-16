
#include "cub3d.h"

/**
 * Initialize mlx
 * @param cube
 *
 * @return void
 */
void	ft_init_mlx(t_cube *cube)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		ft_print_error("mlx_init() failed");
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, PROG_NAME);
	if (!win_ptr)
		ft_print_error("mlx_new_window() failed");
	cube->mlx_ptr = mlx_ptr;
	cube->win_ptr = win_ptr;
}
