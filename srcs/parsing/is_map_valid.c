
#include "cub3d.h"

static t_pos	*ft_find_player(char **map)
{
	t_pos			*pos;
	bool			found;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	found = false;
	pos = malloc(sizeof(pos) * (sizeof(int) * 2) + sizeof(char));
	if (!pos)
		ft_print_error(MSG_MALLOC_ERR);
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'S' || map[y][x] == 'N' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				if (found == true)
					ft_print_error(MSG_TWO_PLAYER_ERR);
				pos->x = x;
				pos->y = y;
				pos->c = map[y][x];
				found = true;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (found == false)
		ft_print_error(MSG_NO_PLAYER_ERR);
	return (pos);
}

static bool	ft_map_is_close(char **map, unsigned int x, unsigned y)
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

static void	ft_map_to_norm(char **map)
{
	unsigned int	x;
	unsigned int	y;
	char			*tmp;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == ' ')
				map[y][x] = '1';
			x++;
		}
		tmp = ft_calloc(sizeof(char), x + 2);
		if (!tmp)
			ft_print_error(MSG_MALLOC_ERR);	
		x = 0;
		while (map[y][x] != '\0')
		{
			tmp[x] = map[y][x];
			x++;
		}
		tmp[x] = '1';
		free(map[y]);
		map[y] = tmp;
		x = 0;
		y++;
	}
}

void	ft_is_map_valid(t_matrix *matrix)
{
	unsigned int	x;
	unsigned int	y;
	char			**map_cpy;

	x = 0;
	y = 0;
	map_cpy = ft_cpy_map_utils(matrix->map);
	matrix->player_pos = ft_find_player(matrix->map);
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
	db_print_array(map_cpy, "MAP_CPY"); // <-- fonction can be delete after check
	ft_free_array(map_cpy);
	ft_map_to_norm(matrix->map);
}
