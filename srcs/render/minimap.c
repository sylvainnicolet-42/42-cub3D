
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
		len = ft_strlen(str[i]);
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

static bool	ft_is_wall(char **map, int x, int y)
{
	int	x_map;
	int	y_map;
	int	max_x;
	int	max_y;

	max_x = ft_strlen_max_x(map);
	max_y = ft_strlen_max_y(map);
	x_map = (x * max_x) / ((WIN_WIDTH / 5) * 1);
	y_map = (y * max_y) / ((WIN_HEIGHT / 5) * 1);
	if ((int)ft_strlen(map[y_map]) < x_map)
		return (true);
	if (ft_strncmp(&map[y_map][x_map], "1", 1) == 0)
		return (true);
	if (ft_strncmp(&map[y_map][x_map], "\0", 1) == 0)
		return (true);
	else
		return (false);
}

void	ft_minimap(t_cube *cube)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;

	start_x = (WIN_WIDTH / 5) * 4;
	start_y = (WIN_HEIGHT / 5) * 4;
	y = start_y;
	while (y < WIN_HEIGHT)
	{
		x = start_x;
		while (x < WIN_WIDTH)
		{
			if (ft_is_wall(cube->matrix->map, x - start_x, y - start_y) == true)
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(50, 160, 0)); // <- wall
			else
				ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(255, 255, 255)); // <- alley
			x++;
		}
		y++;
	}
}
