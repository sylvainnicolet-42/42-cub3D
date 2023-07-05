
#include "cub3d.h"

void	ft_move_forward(t_cube *cube)
{
	(void) cube;
	printf("Move Forward\n");
	cube->player->pos_y -= 1;
	printf("Player pos y [%d]\n", cube->player->pos_y);
}

void	ft_move_backward(t_cube *cube)
{
	(void) cube;
	printf("Move Backward\n");
	cube->player->pos_y += 1;
	printf("Player pos y [%d]\n", cube->player->pos_y);
}

void	ft_move_left(t_cube *cube)
{
	(void) cube;
	printf("Move Left\n");
	cube->player->pos_x -= 1;
	printf("Player pos x [%d]\n", cube->player->pos_x);
}

void	ft_move_right(t_cube *cube)
{
	(void) cube;
	printf("Move Right\n");
	cube->player->pos_x += 1;
	printf("Player pos x [%d]\n", cube->player->pos_x);
}
