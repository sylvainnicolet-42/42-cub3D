
#include "cub3d.h"

t_wall	ft_next_wall_e(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.x++;
	wall.pos.y = pos.y;
	wall.pos.x = pos.x - (pos.x - (int)pos.x);
	wall.direction = E_EAST;
	printf("east\n");
	return (wall);
}

t_wall	ft_next_wall_s(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.y++;
	wall.pos.y = pos.y - (pos.y - (int)pos.y);
	wall.pos.x = pos.x;
	wall.direction = E_SOUTH;
	printf("south\n");
	return (wall);
}

t_wall	ft_next_wall_w(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.x--;
	wall.pos.y = pos.y;
	wall.pos.x = (int)pos.x + 1;
	wall.direction = E_WEST;
	printf("west\n");
	return (wall);
}

t_wall	ft_next_wall_n(t_real pos, char **map)
{
	t_wall	wall;

	while (map[(int)pos.y][(int)pos.x] != '1')
		pos.y--;
	wall.pos.y = (int)pos.y + 1;
	wall.pos.x = pos.x;
	wall.direction = E_NORTH;
	printf("north\n");
	return (wall);
}
