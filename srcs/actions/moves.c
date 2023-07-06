
#include "cub3d.h"

void	ft_move_forward(t_cube *cube)
{
	(void) cube;
	printf("Move Forward\n");
	cube->player->real_y -= D_UNIT;
	printf("Player pos y [%f]\n", cube->player->real_y);
}

void	ft_move_backward(t_cube *cube)
{
	(void) cube;
	printf("Move Backward\n");
	cube->player->real_y += D_UNIT;
	printf("Player pos y [%f]\n", cube->player->real_y);
}

void	ft_move_left(t_cube *cube)
{
	(void) cube;
	printf("Move Left\n");
	cube->player->real_x -= D_UNIT;
	printf("Player pos x [%f]\n", cube->player->real_x);
}

void	ft_move_right(t_cube *cube)
{
	(void) cube;
	printf("Move Right\n");
	cube->player->real_x += D_UNIT;
	printf("Player pos x [%f]\n", cube->player->real_x);
}
