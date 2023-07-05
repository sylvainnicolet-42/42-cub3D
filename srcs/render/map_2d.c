
#include "cub3d.h"

/*      0|1|2|3|4
 *    ____________
 * 0] | 1|1|1|1|1
 * 1] | 1|0|0|0|1
 * 2] | 1|0|0|0|1
 * 3] | 1|0|0|0|1
 * 4] | 1|1|1|1|1
 *
 * x->start = (WIN_WIDTH / 5) * 4
 * x->end = WIN_WIDTH
 *
 * max_len = (strlen(char *str_longer)) - 1
 *
 */

static int	ft_strlen_max_x(char **str)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (str[i] != NULL)
	{
		len = (int) ft_strlen(str[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max - 1);
}

static int	ft_strlen_max_y(char **str)
{
	int	len;

	len = 0;
	while (str[len] != NULL)
		len++;
	return (len);
}

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
	int	max_x;
	int	max_y;

	max_x = ft_strlen_max_x(cube->map);
	max_y = ft_strlen_max_y(cube->map);
	x_map = (x * max_x) / (WIN_WIDTH / 2);
	y_map = (y * max_y) / WIN_HEIGHT;
	if ((int)ft_strlen(cube->map[y_map]) < x_map)
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
}
