
#include "cub3d.h"

static int	ft_is_wall(t_cube *cube, int x, int y)
{
	int	y_map;
	int	x_map;

	y_map = (y * cube->map_max_y) / WIN_HEIGHT;
	x_map = (x * cube->map_max_x) / (WIN_WIDTH / 2);
	if (cube->map_max_x < x_map)
		return (E_WALL);
	if (cube->map[y_map][x_map] == '1')
		return (E_WALL);
	if (cube->map[y_map][x_map] == '\0')
		return (E_WALL);
	return (E_ALLEY);
}

void	ft_minimap(t_cube *cube)
{
	int	y;
	int	x;

	x = 0;
	while (x < WIN_WIDTH / 2)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (ft_is_wall(cube, x, y) == E_WALL)
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(50, 160, 0));
			else
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(0, 0, 0));
			y++;
		}
		x++;
	}
}
