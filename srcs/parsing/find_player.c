
#include "cub3d.h"

static void	ft_set_player(char c, t_player *pos, unsigned int x, unsigned int y)
{
	pos->pos_x = x;
	pos->pos_y = y;
	pos->dir_x = 0;
	pos->dir_y = 0;
	pos->plane_x = 0;
	pos->plane_y = (float) FOV / 100;
	if (c == 'N')
		pos->dir_y = 1;
	else if (c == 'S')
		pos->dir_y = -1;
	else if (c == 'W')
		pos->dir_x = -1;
	else if (c == 'E')
		pos->dir_x = 1;
}

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
				ft_set_player(map[y][x], pos, x, y);
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
