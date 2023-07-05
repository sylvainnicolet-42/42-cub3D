
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

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
