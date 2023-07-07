
#include "cub3d.h"

bool	ft_collision_forw(char **map, t_real *real, float x_p, float y_p)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	x_p += real->x;
	y_p += real->y;
	if (map[(int)(y_p + sc)][(int)(x_p + sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p + sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p + sc)] == '1')
		return (false);
	return (true);
}

bool	ft_collision_back(char **map, t_real *real, float x_p, float y_p)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	x_p = real->x - x_p;
	y_p = real->y - y_p;
	if (map[(int)(y_p + sc)][(int)(x_p + sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p + sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p + sc)] == '1')
		return (false);
	return (true);
}

bool	ft_collision_left(char **map, t_real *real, float x_p, float y_p)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	y_p += real->x;
	x_p = real->y - x_p;
	if (map[(int)(y_p + sc)][(int)(x_p + sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p + sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p + sc)] == '1')
		return (false);
	return (true);
}

bool	ft_collision_right(char **map, t_real *real, float x_p, float y_p)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	y_p = real->x - y_p;
	x_p += real->y;
	if (map[(int)(y_p + sc)][(int)(x_p + sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p + sc)][(int)(x_p - sc)] == '1')
		return (false);
	if (map[(int)(y_p - sc)][(int)(x_p + sc)] == '1')
		return (false);
	return (true);
}
