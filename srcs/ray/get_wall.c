
#include "cub3d.h"

t_real	ft_get_wall(t_cube *cube, int angle, float rad)
{
	t_real	wall;

	wall.x = 0;
	wall.y = 0;
	if (angle == 0 || angle == 360)
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
	return (wall);
}
