
#include "cub3d.h"

/**
 * Handle events on the window
 * @param cube
 *
 * @return void
 */
void	ft_handle_event(t_cube *cube)
{
	if (D_LINUX == 1)
		mlx_hook(cube->win_ptr, E_KEY_PRESS, 1L, ft_key_hook_linux, cube);
	else
		mlx_hook(
			cube->win_ptr, E_KEY_PRESS, E_KEY_PRESS_MASK, ft_key_hook, cube);
	mlx_hook(cube->win_ptr, E_ON_MOUSEDOWN, 0, ft_mouse_press, cube);
	mlx_hook(cube->win_ptr, E_ON_MOUSEMOVE, 0, ft_mouse_hook, cube);
	mlx_hook(cube->win_ptr, E_ON_MOUSEUP, 0, ft_mouse_release, cube);
	mlx_hook(cube->win_ptr, E_ON_DESTROY, E_KEY_PRESS_MASK, ft_close, cube);
	mlx_loop_hook(cube->mlx_ptr, ft_render_next_frame, cube);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
