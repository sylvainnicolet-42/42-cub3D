
#include "cub3d.h"

/**
 * Apply the key
 * @param key
 * @param cube
 *
 * @return void
 */
static void	ft_apply_key(int key, t_cube *cube)
{
	if (key == E_KEY_W)
		ft_move_forward(cube);
	else if (key == E_KEY_S)
		ft_move_backward(cube);
	else if (key == E_KEY_A)
		ft_move_left(cube);
	else if (key == E_KEY_D)
		ft_move_right(cube);
	else if (key == E_KEY_R)
		ft_print_ray_v2(cube, cube->player->facing);
	else if (key == E_KEY_ARROW_LEFT)
		ft_move_vision_left(cube);
	else if (key == E_KEY_ARROW_RIGHT)
		ft_move_vision_right(cube);
	else if (key == E_KEY_ESC)
		ft_close(cube);
}

/**
 * Handle key events
 * @param key
 * @param cube
 * @return
 */
int	ft_key_hook(int key, t_cube *cube)
{
	ft_apply_key(key, cube);
	return (0);
}
