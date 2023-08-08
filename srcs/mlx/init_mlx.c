
#include "cub3d.h"

static t_img	*ft_init_img(t_cube *cube)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(cube->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	return (img);
}

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
	cube->img = ft_init_img(cube);
}
