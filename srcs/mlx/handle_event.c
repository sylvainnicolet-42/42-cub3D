
#include "cub3d.h"

/**
 * Handle events on the window
 * @param cube
 *
 * @return void
 */
void	ft_handle_event(t_cube *cube)
{
	mlx_hook(cube->win_ptr, E_KEY_PRESS, E_KEY_PRESS_MASK, ft_key_hook, cube);
	mlx_hook(cube->win_ptr, E_ON_DESTROY, E_KEY_PRESS_MASK, ft_close, cube);
}
