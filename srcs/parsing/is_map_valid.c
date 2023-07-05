
#include "cub3d.h"

static bool	ft_map_is_close(char **map, unsigned int x, unsigned int y)
{
	if (map[y][x] == 'f')
		return (true);
	if (map[y] == NULL)
		return (false);
	if (map[y][x] == '1')
		return (true);
	if (x <= 0 || y <= 0)
		return (false);
	if (ft_is_valid_char_map_utils(map[y][x]) == true)
		map[y][x] = 'f';
	else
		ft_print_error(MSG_MAP_NOT_VALID_ERR);
	if (ft_map_is_close(map, x + 1, y) == false)
		ft_print_error(MSG_MAP_NOT_CLOSE_ERR);
	if (ft_map_is_close(map, x - 1, y) == false)
		ft_print_error(MSG_MAP_NOT_CLOSE_ERR);
	if (ft_map_is_close(map, x, y + 1) == false)
		ft_print_error(MSG_MAP_NOT_CLOSE_ERR);
	if (ft_map_is_close(map, x, y - 1) == false)
		ft_print_error(MSG_MAP_NOT_CLOSE_ERR);
	return (true);
}

static void	ft_fill_one(char **map)
{
	int y;
	int x;
	int max;
	int len;

	x = 0;
	y = 0;
	max = 0;
	len = 0;
	while (map[y][x] != '\0')
	{
		if (x > max)
			max = x;
		x++;
	}
	x = 0;
}

static void	ft_map_to_norm_ext(char **map, unsigned int *x, unsigned int *y)
{
	char	*tmp;

	while (map[*y][*x] != '\0')
	{
		if (map[*y][*x] == ' ')
			map[*y][*x] = '1';
		(*x)++;
	}
	tmp = ft_calloc(sizeof(char), *x + 2);
	if (!tmp)
		ft_print_error(MSG_MALLOC_ERR);
	*x = 0;
	while (map[*y][*x] != '\0')
	{
		tmp[*x] = map[*y][*x];
		(*x)++;
	}
	tmp[*x] = '1';
	free(map[*y]);
	map[*y] = tmp;
	*x = 0;
	(*y)++;
}

static void	ft_map_to_norm(char **map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
		ft_map_to_norm_ext(map, &x, &y);
	ft_fill_one(map);
}

void	ft_is_map_valid(t_cube *cube)
{
	unsigned int	x;
	unsigned int	y;
	char			**map_cpy;

	x = 0;
	y = 0;
	map_cpy = ft_cpy_map_utils(cube->map);
	cube->player = ft_find_player(cube->map);
	while (map_cpy[y] != NULL)
	{
		while (map_cpy[y][x] != '\0')
		{
			if (map_cpy[y][x] == '0')
			{
				if (ft_map_is_close(map_cpy, x, y) == false)
					ft_print_error(MSG_MAP_NOT_CLOSE_ERR);
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_free_array(map_cpy);
	ft_map_to_norm(cube->map);
}
