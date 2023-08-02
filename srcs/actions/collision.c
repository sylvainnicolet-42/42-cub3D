
#include "cub3d.h"

bool	ft_collision_forw(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_x += real->x;
	d_y += real->y;
	if (map[(int)(d_y + sc)][(int)(d_x + sc)] == '1')
		return (false);
	if (map[(int)(d_y - sc)][(int)(d_x - sc)] == '1')
		return (false);
	if (map[(int)(d_y + sc)][(int)(d_x - sc)] == '1')
		return (false);
	if (map[(int)(d_y - sc)][(int)(d_x + sc)] == '1')
		return (false);
	return (true);
}

bool	ft_collision_back(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_x = real->x - d_x;
	d_y = real->y - d_y;
	if (map[(int)(d_y + sc)][(int)(d_x + sc)] == '1')
		return (false);
	if (map[(int)(d_y - sc)][(int)(d_x - sc)] == '1')
		return (false);
	if (map[(int)(d_y + sc)][(int)(d_x - sc)] == '1')
		return (false);
	if (map[(int)(d_y - sc)][(int)(d_x + sc)] == '1')
		return (false);
	return (true);
}

bool	ft_collision_left(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_y += real->x;
	d_x = real->y - d_x;
	if (map[(int)(d_x + sc)][(int)(d_y + sc)] == '1')
		return (false);
	if (map[(int)(d_x - sc)][(int)(d_y - sc)] == '1')
		return (false);
	if (map[(int)(d_x + sc)][(int)(d_y - sc)] == '1')
		return (false);
	if (map[(int)(d_x - sc)][(int)(d_y + sc)] == '1')
		return (false);
	return (true);
}

bool	ft_collision_right(char **map, t_real *real, float d_x, float d_y)
{
	float	sc;

	sc = D_PLAYER_SCALE / 2;
	d_y = real->x - d_y;
	d_x += real->y;
	if (map[(int)(d_x + sc)][(int)(d_y + sc)] == '1')
		return (false);
	if (map[(int)(d_x - sc)][(int)(d_y - sc)] == '1')
		return (false);
	if (map[(int)(d_x + sc)][(int)(d_y - sc)] == '1')
		return (false);
	if (map[(int)(d_x - sc)][(int)(d_y + sc)] == '1')
		return (false);
	return (true);
}
