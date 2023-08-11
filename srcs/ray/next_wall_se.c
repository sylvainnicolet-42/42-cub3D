
#include "cub3d.h"

static t_wall_values	ft_init_values(t_real pos, float rad)
{
	t_wall_values	wall_values;

	wall_values.distance.y = (int)pos.y + 1 - pos.y;
	wall_values.distance.x = (int)pos.x + 1 - pos.x;
	wall_values.hypo.y = floor(
			1000000 * (wall_values.distance.y / sin(rad))) / 1000000;
	wall_values.hypo.x = floor(
			1000000 * (wall_values.distance.x / cos(rad))) / 1000000;
	return (wall_values);
}

t_wall	ft_next_wall_se(float rad, t_real pos, char **map)
{
	t_wall_values	w;
	t_wall			wall;

	w = ft_init_values(pos, rad);
	if (w.hypo.y == w.hypo.x)
	{
		w.wall.y = pos.y + (w.distance.y * tan(rad));
		w.wall.x = pos.x + (w.distance.x / tan(rad));
		wall.pos.y = w.wall.y;
		wall.pos.x = w.wall.x;
		wall.direction = E_WEST;
		if (map[(int)pos.y + 1][(int)pos.x + 1] != '1')
			wall = ft_next_wall_se(rad, w.wall, map);
	}
	else if (w.hypo.y < w.hypo.x)
	{
		w.wall.y = pos.y + w.distance.y;
		w.wall.x = pos.x + (w.distance.y / tan(rad));
		wall.pos.y = w.wall.y;
		wall.pos.x = w.wall.x;
		wall.direction = E_WEST;
		if (map[(int)pos.y + 1][(int)pos.x] != '1')
			wall = ft_next_wall_se(rad, w.wall, map);
	}
	else
	{
		w.wall.y = pos.y + (w.distance.x * tan(rad));
		w.wall.x = pos.x + w.distance.x;
		wall.pos.y = w.wall.y;
		wall.pos.x = w.wall.x;
		wall.direction = E_NORTH;
		if (map[(int)pos.y][(int)pos.x + 1] != '1')
			wall = ft_next_wall_se(rad, w.wall, map);
	}
	return (wall);
}
