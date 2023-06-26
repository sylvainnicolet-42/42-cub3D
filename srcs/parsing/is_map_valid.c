
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
	pos = malloc(sizeof(pos));
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
				found = true;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

void	ft_is_map_valid(t_matrix *matrix)
{
	matrix->player = ft_find_player(matrix->map);

}
