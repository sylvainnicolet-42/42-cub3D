
#include "cub3d.h"

t_real	ft_next_wall_e(t_real pos, char **map)
{
	t_real	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.x++;
	wall.y = pos.y;
	wall.x = pos.x - (pos.x - (int)pos.x);
	return (wall);
}

t_real	ft_next_wall_s(t_real pos, char **map)
{
	t_real	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.y++;
	wall.y = pos.y - (pos.y - (int)pos.y);
	wall.x = pos.x;
	return (wall);
}

t_real	ft_next_wall_w(t_real pos, char **map)
{
	t_real	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.x--;
	wall.y = pos.y;
	wall.x = (int)pos.x + 1;
	return (wall);
}

t_real	ft_next_wall_n(t_real pos, char **map)
{
	t_real	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.y--;
	wall.y = (int)pos.y + 1;
	wall.x = pos.x;
	return (wall);
}
