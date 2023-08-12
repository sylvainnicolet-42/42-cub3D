
#include "cub3d.h"

void	ft_open_door(t_cube *cube)
{
	t_wall	wall;
	float	distance;

	wall = ft_get_wall(cube, cube->player->facing);
	distance = ft_get_distance(cube, wall, cube->player->facing);
	if (cube->player->facing > D_WEST - 0.000001 && cube->player->facing < D_WEST + 0.000001)
		wall.pos.x -= 1;
	else if (cube->player->facing > D_NORTH - 0.000001 && cube->player->facing < D_NORTH + 0.000001)
		wall.pos.y -= 1;
	printf("map[%d][%d] = [%c]\n", (int)wall.pos.y, (int)wall.pos.x, cube->map[(int)wall.pos.y][(int)wall.pos.x]);
	printf("y[%f] x[%f]\n", wall.pos.y, wall.pos.x);
	printf("distance [%f]\n", distance);
	if (wall.door == false)
		printf("No Door\n");
	if (wall.door == true)
	{
		if (distance < 1.15)
			cube->map[(int)wall.pos.y][(int)wall.pos.x] = '0';
	}
}
