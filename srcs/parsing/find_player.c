
#include "cub3d.h"

static bool	ft_find_player_ext(char **map, t_player *pos, unsigned int x,
	unsigned int y)
{
	bool			found;

	found = false;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'S' || map[y][x] == 'N' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				if (found == true)
					ft_print_error(MSG_TWO_PLAYER_ERR);
				pos->pos_x = x;
				pos->pos_x = y;
				found = true;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (found);
}

t_player	*ft_find_player(char **map)
{
	t_player		*pos;
	bool			found;

	pos = malloc(sizeof(t_player));
	if (!pos)
		ft_print_error(MSG_MALLOC_ERR);
	found = ft_find_player_ext(map, pos, 0, 0);
	if (found == false)
		ft_print_error(MSG_NO_PLAYER_ERR);
	return (pos);
}
