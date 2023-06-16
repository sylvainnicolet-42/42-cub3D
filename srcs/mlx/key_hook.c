
#include "cub3d.h"

/**
 * Check if the key is a valid key
 * @param cube
 *
 * @return bool, true if the key is valid else false
 */
static bool	ft_is_key(int key)
{
	return (key == E_KEY_ESC);
}

/**
 * Apply the key
 * @param key
 * @param cube
 *
 * @return void
 */
static void	ft_apply_key(int key, t_cube *cube)
{
	if (key == E_KEY_ESC)
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
	if (ft_is_key(key))
		ft_apply_key(key, cube);
	return (0);
}
