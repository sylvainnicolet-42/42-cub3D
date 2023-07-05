
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
	len = 0;
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

static bool	ft_is_player(t_pos *player, int x, int y)
{
	if ((unsigned int)x == player->x && (unsigned int)y == player->y)
		return (true);
	return (false);
}	

static int	ft_is_wall(t_cube *cube, int x, int y)
{
	int	x_map;
	int	y_map;
	int	max_x;
	int	max_y;

	max_x = ft_strlen_max_x(cube->matrix->map);
	max_y = ft_strlen_max_y(cube->matrix->map);
	x_map = (x * max_x) / ((WIN_WIDTH / 5) * 1);
	y_map = (y * max_y) / ((WIN_HEIGHT / 5) * 1);
	if ((int)ft_strlen(cube->matrix->map[y_map]) < x_map)
		return (E_WALL);
	if (ft_strncmp(&cube->matrix->map[y_map][x_map], "1", 1) == 0)
		return (E_WALL);
	if (ft_strncmp(&cube->matrix->map[y_map][x_map], "\0", 1) == 0)
		return (E_WALL);
	if (ft_is_player(cube->matrix->player_pos, x_map, y_map) == true)
		return (E_PLAYER);
	return (E_ALLEY);
}

void	ft_minimap(t_cube *cube)
{
	int	x;
	int	y;
	int	st_x;
	int	st_y;

	st_x = (WIN_WIDTH / 5) * 4;
	st_y = (WIN_HEIGHT / 5) * 4;
	y = st_y;
	while (y < WIN_HEIGHT)
	{
		x = st_x;
		while (x < WIN_WIDTH)
		{
			if (ft_is_wall(cube, x - st_x, y - st_y) == E_WALL)
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(50, 160, 0));
			else if (ft_is_wall(cube, x - st_x, y - st_y) == E_PLAYER)
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(255, 255, 255));
			else
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(0, 0, 0));
			x++;
		}
		y++;
	}
}
