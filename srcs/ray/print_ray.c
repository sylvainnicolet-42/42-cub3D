
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

t_real	ft_next_wall_se(float rad, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	direction;

	direction = rad;						// angle is 0 to 90
	distance.y = (int)pos.y + 1 - pos.y;	// go + in y
	distance.x = (int)pos.x + 1 - pos.x;	// go + in x
	hypo.y = floor(1000000 * (distance.y / sin(direction))) / 1000000;
	hypo.x = floor(1000000 * (distance.x / cos(direction))) / 1000000;
	if (hypo.y == hypo.x)
	{
		wall.y = pos.y + (distance.y * tan(direction));
		wall.x = pos.x + (distance.x / tan(direction));
		if (map[(int)pos.y + 1][(int)pos.x + 1] != '1')
			wall = ft_next_wall_se(rad, wall, map);
	}
	else if (hypo.y < hypo.x)
	{
		wall.y = pos.y + distance.y;
		wall.x = pos.x + (distance.y / tan(direction));
		if (map[(int)pos.y + 1][(int)pos.x] != '1')
			wall = ft_next_wall_se(rad, wall, map);
	}
	else 
	{
		wall.y = pos.y + (distance.x * tan(direction));
		wall.x = pos.x + distance.x;
		if (map[(int)pos.y][(int)pos.x + 1] != '1')
			wall = ft_next_wall_se(rad, wall, map);
		
	}
	return (wall);
}

t_real	ft_next_wall_sw(float rad, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	direction;
	int		offset;

	offset = 0;
	direction = M_PI - rad;					// angle is 90 to 180
	distance.y = (int)pos.y + 1 - pos.y;	// go + in y
	distance.x = pos.x - (int)pos.x;		// go - in x
	if (distance.x == 0)
	{
		offset = 1;
		distance.x = 1;
	}
	hypo.y = floor(1000000 * (distance.y / sin(direction))) / 1000000;
	hypo.x = floor(1000000 * (distance.x / cos(direction))) / 1000000;
	if (hypo.y == hypo.x)
	{
		wall.y = pos.y + (distance.y * tan(direction));
		wall.x = pos.x - (distance.x / tan(direction));
		if (map[(int)pos.y + 1][(int)pos.x - 1 - offset] != '1')
			wall = ft_next_wall_sw(rad, wall, map);
	}
	else if (hypo.y < hypo.x)
	{
		wall.y = pos.y + distance.y;
		wall.x = pos.x - (distance.y / tan(direction));
		if (map[(int)pos.y + 1][(int)pos.x - offset] != '1')
			wall = ft_next_wall_sw(rad, wall, map);
	}
	else
	{
		wall.y = pos.y + (distance.x * tan(direction));
		wall.x = pos.x - distance.x;
		if (map[(int)pos.y][(int)pos.x - 1 - offset] != '1')
			wall = ft_next_wall_sw(rad, wall, map);
	}
	return (wall);
}

t_real	ft_next_wall_nw(float rad, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	direction;
	int		offset_x;
	int		offset_y;

	offset_y = 0;
	offset_x = 0;
	direction = rad - M_PI;				// angle is 180 to 270
	distance.y = pos.y - (int)pos.y;	// go - in y
	distance.x = pos.x - (int)pos.x;	// go - in x
	if (distance.y == 0)
	{
		offset_y = 1;
		distance.y = 1;
	}
	if (distance.x == 0)
	{
		offset_x = 1;
		distance.x = 1;
	}
	hypo.y = floor(1000000 * (distance.y / sin(direction))) / 1000000;
	hypo.x = floor(1000000 * (distance.x / cos(direction))) / 1000000;
	if (hypo.y == hypo.x)
	{
		wall.y = pos.y - (distance.y * tan(direction));
		wall.x = pos.x - (distance.x / tan(direction));
		if (map[(int)pos.y - 1 - offset_y][(int)pos.x - 1 - offset_x] != '1')
			wall = ft_next_wall_nw(rad, wall, map);
	}
	else if (hypo.y < hypo.x)
	{
		wall.y = pos.y - distance.y;
		wall.x = pos.x - (distance.y / tan(direction));
		if (map[(int)pos.y - 1 - offset_y][(int)pos.x - offset_x] != '1')
			wall = ft_next_wall_nw(rad, wall, map);
	}
	else
	{
		wall.y = pos.y - (distance.x * tan(direction));
		wall.x = pos.x - distance.x;
		if (map[(int)pos.y - offset_y][(int)pos.x - 1 - offset_x] != '1')
			wall = ft_next_wall_nw(rad, wall, map);
		
	}
	return (wall);
}

t_real	ft_next_wall_ne(float rad, t_real pos, char **map)
{
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	float	direction;
	int		offset;

	offset = 0;
	direction = (2 * M_PI) - rad;			// angle is 270 to 360
	distance.y = pos.y - (int)pos.y;		// go - in y
	distance.x = (int)pos.x + 1 - pos.x;	// go + in x
	if (distance.y == 0)
	{
		offset = 1;
		distance.y = 1;
	}
	hypo.y = floor(1000000 * (distance.y / sin(direction))) / 1000000;
	hypo.x = floor(1000000 * (distance.x / cos(direction))) / 1000000;
	if (hypo.y == hypo.x)
	{
		wall.y = pos.y - (distance.y * tan(direction));
		wall.x = pos.x + (distance.x / tan(direction));
		if (map[(int)pos.y - 1 - offset][(int)pos.x + 1] != '1')
			wall = ft_next_wall_ne(rad, wall, map);
	}
	else if (hypo.y < hypo.x)
	{
		wall.y = pos.y - distance.y;
		wall.x = pos.x + (distance.y / tan(direction));
		if (map[(int)pos.y - 1 - offset][(int)pos.x] != '1')
			wall = ft_next_wall_ne(rad, wall, map);
	}
	else
	{
		wall.y = pos.y - (distance.x * tan(direction));
		wall.x = pos.x + distance.x;
		if (map[(int)pos.y - offset][(int)pos.x + 1] != '1')
			wall = ft_next_wall_ne(rad, wall, map);
	}
	return (wall);
}

t_real	ft_print_ray(t_cube *cube, int angle, float rad)
{
	t_real	wall;
	t_rgb	color;

	color.r = 0;
	color.g = 0;
	color.b = 255;
	if (angle == 360)
		wall = ft_next_wall_e(*cube->player->real, cube->map);
	else if (angle == 90)
		wall = ft_next_wall_s(*cube->player->real, cube->map);
	else if (angle == 180)
		wall = ft_next_wall_w(*cube->player->real, cube->map);
	else if (angle == 270)
		wall = ft_next_wall_n(*cube->player->real, cube->map);
	else if (angle > 0 && angle < 90)
		wall = ft_next_wall_se(rad, *cube->player->real, cube->map);
	else if (angle > 90 && angle < 180)
		wall = ft_next_wall_sw(rad, *cube->player->real, cube->map);
	else if (angle > 180 && angle < 270)
		wall = ft_next_wall_nw(rad, *cube->player->real, cube->map);
	else if (angle > 270 && angle <= 359)
		wall = ft_next_wall_ne(rad, *cube->player->real, cube->map);
//	ft_draw_cube(cube, &wall, 0.05, &color);
	ft_draw_line(cube, &wall, &color);
	return (wall);
}
