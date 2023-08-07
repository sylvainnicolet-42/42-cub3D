
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

t_real	ft_next_wall_se(float rad, t_real pos, char **map)
{
	t_wall_values	wall_values;

	wall_values = ft_init_values(pos, rad);
	if (wall_values.hypo.y == wall_values.hypo.x)
	{
		wall_values.wall.y = pos.y + (wall_values.distance.y * tan(rad));
		wall_values.wall.x = pos.x + (wall_values.distance.x / tan(rad));
		if (map[(int)pos.y + 1][(int)pos.x + 1] != '1')
			wall_values.wall = ft_next_wall_se(rad, wall_values.wall, map);
	}
	else if (wall_values.hypo.y < wall_values.hypo.x)
	{
		wall_values.wall.y = pos.y + wall_values.distance.y;
		wall_values.wall.x = pos.x + (wall_values.distance.y / tan(rad));
		if (map[(int)pos.y + 1][(int)pos.x] != '1')
			wall_values.wall = ft_next_wall_se(rad, wall_values.wall, map);
	}
	else
	{
		wall_values.wall.y = pos.y + (wall_values.distance.x * tan(rad));
		wall_values.wall.x = pos.x + wall_values.distance.x;
		if (map[(int)pos.y][(int)pos.x + 1] != '1')
			wall_values.wall = ft_next_wall_se(rad, wall_values.wall, map);
	}
	return (wall_values.wall);
}
