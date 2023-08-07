
#include "cub3d.h"

static t_wall_values	ft_init_values(t_real pos, float rad)
{
	t_wall_values	wall_val;

	wall_val.dir = M_PI - rad;
	wall_val.distance.y = (int)pos.y + 1 - pos.y;
	wall_val.distance.x = pos.x - (int)pos.x;
	wall_val.of7.x = 0;
	if (wall_val.distance.x == 0)
	{
		wall_val.of7.x = 1;
		wall_val.distance.x = 1;
	}
	wall_val.hypo.y = floor(
			1000000 * (wall_val.distance.y / sin(wall_val.dir))) / 1000000;
	wall_val.hypo.x = floor(
			1000000 * (wall_val.distance.x / cos(wall_val.dir))) / 1000000;
	return (wall_val);
}

t_real	ft_next_wall_sw(float rad, t_real pos, char **map)
{
	t_wall_values	wall_val;

	wall_val = ft_init_values(pos, rad);
	if (wall_val.hypo.y == wall_val.hypo.x)
	{
		wall_val.wall.y = pos.y + (wall_val.distance.y * tan(wall_val.dir));
		wall_val.wall.x = pos.x - (wall_val.distance.x / tan(wall_val.dir));
		if (map[(int)pos.y + 1][(int)(pos.x - 1 - wall_val.of7.x)] != '1')
			wall_val.wall = ft_next_wall_sw(rad, wall_val.wall, map);
	}
	else if (wall_val.hypo.y < wall_val.hypo.x)
	{
		wall_val.wall.y = pos.y + wall_val.distance.y;
		wall_val.wall.x = pos.x - (wall_val.distance.y / tan(wall_val.dir));
		if (map[(int)pos.y + 1][(int)(pos.x - wall_val.of7.x)] != '1')
			wall_val.wall = ft_next_wall_sw(rad, wall_val.wall, map);
	}
	else
	{
		wall_val.wall.y = pos.y + (wall_val.distance.x * tan(wall_val.dir));
		wall_val.wall.x = pos.x - wall_val.distance.x;
		if (map[(int)pos.y][(int)(pos.x - 1 - wall_val.of7.x)] != '1')
			wall_val.wall = ft_next_wall_sw(rad, wall_val.wall, map);
	}
	return (wall_val.wall);
}
