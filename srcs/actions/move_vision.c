
#include "cub3d.h"

void	ft_move_vision_left(t_cube *cube)
{
	printf("Look Left\n");
	cube->player->facing -= 0.25;
	cube->player->facing = fmod(cube->player->facing, 2 * M_PI);
}

void	ft_move_vision_right(t_cube *cube)
{
	(void) cube;
	cube->player->facing += 0.25;
	cube->player->facing = fmod(cube->player->facing, 2 * M_PI);
}
