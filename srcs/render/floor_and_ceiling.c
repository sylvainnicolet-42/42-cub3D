
#include "cub3d.h"

void	ft_floor_and_ceiling(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			if (y < WIN_HEIGHT / 2)
				ft_mlx_pixel_put(cube->img, x, y, 
					ft_encode_rgb(cube->c->r, cube->c->g, cube->c->b));
			else
				ft_mlx_pixel_put(cube->img, x, y, 
					ft_encode_rgb(cube->f->r, cube->f->g, cube->f->b));
			y++;
		}
		y = 0;
		x++;
	}
}
