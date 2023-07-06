
#include "cub3d.h"

void	ft_move_forward(t_cube *cube)
{
	double	x_p;
	double	y_p;

	x_p = cos(cube->player->facing) * D_UNIT;
	y_p = sin(cube->player->facing) * D_UNIT;
	cube->player->real->x += x_p;
	cube->player->real->y += y_p;
	printf("Move Forward\n");
	printf("Player pos y [%f]\n", cube->player->real->y);
	printf("Player pos x [%f]\n", cube->player->real->x);
}

void	ft_move_backward(t_cube *cube)
{
	double	x_p;
	double	y_p;

	x_p = cos(cube->player->facing) * D_UNIT;
	y_p = sin(cube->player->facing) * D_UNIT;
	cube->player->real->x -= x_p;
	cube->player->real->y -= y_p;
	printf("Move Backward\n");
	printf("Player pos y [%f]\n", cube->player->real->y);
	printf("Player pos x [%f]\n", cube->player->real->x);
}

void	ft_move_left(t_cube *cube)
{
	(void) cube;
	printf("Move Left\n");
	printf("Player pos y [%f]\n", cube->player->real->y);
	printf("Player pos x [%f]\n", cube->player->real->x);
}

void	ft_move_right(t_cube *cube)
{
	(void) cube;
	printf("Move Right\n");
	printf("Player pos y [%f]\n", cube->player->real->y);
	printf("Player pos x [%f]\n", cube->player->real->x);
}
