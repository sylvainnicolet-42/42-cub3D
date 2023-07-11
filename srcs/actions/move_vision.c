
#include "cub3d.h"

void	ft_move_vision_left(t_cube *cube)
{
	printf("Look Left\n");
	cube->player->facing -= (M_PI_2 / 25);
	if (cube->player->facing < 0)
		cube->player->facing += (M_PI * 2);
	printf("Player facing [%f]\n", cube->player->facing);
}

void	ft_move_vision_right(t_cube *cube)
{
	printf("Look Right\n");
	cube->player->facing += (M_PI_2 / 25);
	if (cube->player->facing > M_PI * 2)
		cube->player->facing -= (M_PI * 2);
	printf("Player facing [%f]\n", cube->player->facing);
}
