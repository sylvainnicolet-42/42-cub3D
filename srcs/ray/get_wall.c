
#include "cub3d.h"

t_wall	ft_get_wall(t_cube *cube, float rad)
{
	t_wall	wall;

	wall.pos.x = 0;
	wall.pos.y = 0;
	if (rad == D_EAST)
		wall = ft_next_wall_e(*cube->player->real, cube->map);
	else if (rad == D_SOUTH)
		wall = ft_next_wall_s(*cube->player->real, cube->map);
	else if (rad == D_WEST)
		wall = ft_next_wall_w(*cube->player->real, cube->map);
	else if (rad == D_NORTH)
		wall = ft_next_wall_n(*cube->player->real, cube->map);
	else if (rad > D_EAST && rad < D_SOUTH)
		wall = ft_next_wall_se(rad, *cube->player->real, cube->map);
	else if (rad > D_SOUTH && rad < D_WEST)
		wall = ft_next_wall_sw(rad, *cube->player->real, cube->map);
	else if (rad > D_WEST && rad < D_NORTH)
		wall = ft_next_wall_nw(rad, *cube->player->real, cube->map);
	else
		wall = ft_next_wall_ne(rad, *cube->player->real, cube->map);
	return (wall);
}
