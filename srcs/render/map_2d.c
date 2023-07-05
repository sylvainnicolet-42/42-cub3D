
#include "cub3d.h"

/*      0|1|2|3|4
 *    ____________
 * 0] | 1|1|1|1|1
 * 1] | 1|0|0|0|1
 * 2] | 1|0|0|0|1
 * 3] | 1|0|0|0|1
 * 4] | 1|1|1|1|1
 *
 */

static bool	ft_is_player(t_player *player, int x, int y)
{
	if ((unsigned int)x == player->pos_x && (unsigned int)y == player->pos_y)
		return (true);
	return (false);
}

static int	ft_is_wall(t_cube *cube, int x, int y)
{
	int	x_map;
	int	y_map;

	x_map = (x * cube->map_max_x) / (WIN_WIDTH / 2);
	y_map = (y * cube->map_max_y) / WIN_HEIGHT;
	if (cube->map_max_x < x_map)
		return (E_WALL);
	if (cube->map[y_map][x_map] == '1')
		return (E_WALL);
	if (cube->map[y_map][x_map] == '\0')
		return (E_WALL);
	if (ft_is_player(cube->player, x_map, y_map) == true)
		return (E_PLAYER);
	return (E_ALLEY);
}

void	ft_map_2d(t_cube *cube)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH / 2)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (ft_is_wall(cube, x, y) == E_WALL)
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(50, 160, 0));
			else if (ft_is_wall(cube, x, y) == E_PLAYER)
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(255, 255, 255));
			else
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(0, 0, 0));
			y++;
		}
		x++;
	}
	ft_print_player(cube);
}
