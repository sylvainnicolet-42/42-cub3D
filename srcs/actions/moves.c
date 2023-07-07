
#include "cub3d.h"

void	ft_move_forward(t_cube *cube)
{
	double	x_p;
	double	y_p;

	x_p = cos(cube->player->facing) * D_UNIT;
	y_p = sin(cube->player->facing) * D_UNIT;
	if (ft_collision_forw(cube->map, cube->player->real, x_p, y_p) == true)
	{
		cube->player->real->x += x_p;
		cube->player->real->y += y_p;
		printf("Move Forward\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
	}
	else
		printf("Forward walk into a Wall\n");
}

void	ft_move_backward(t_cube *cube)
{
	double	x_p;
	double	y_p;

	x_p = cos(cube->player->facing) * D_UNIT;
	y_p = sin(cube->player->facing) * D_UNIT;
	if (ft_collision_back(cube->map, cube->player->real, x_p, y_p) == true)
	{
		cube->player->real->x -= x_p;
		cube->player->real->y -= y_p;
		printf("Move Backward\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
	}
	else
		printf("Backward walk into a Wall\n");
}

void	ft_move_left(t_cube *cube)
{
	double	x_p;
	double	y_p;

	x_p = cos(cube->player->facing) * D_UNIT;
	y_p = sin(cube->player->facing) * D_UNIT;
	if (ft_collision_left(cube->map, cube->player->real, x_p, y_p) == true)
	{
		cube->player->real->x += y_p;
		cube->player->real->y -= x_p;
		printf("Move Left\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
	}
	else
		printf("Left walk into a Wall\n");
}

void	ft_move_right(t_cube *cube)
{
	double	x_p;
	double	y_p;

	x_p = cos(cube->player->facing) * D_UNIT;
	y_p = sin(cube->player->facing) * D_UNIT;
	if (ft_collision_right(cube->map, cube->player->real, x_p, y_p) == true)
	{
		cube->player->real->x -= y_p;
		cube->player->real->y += x_p;
		printf("Move Right\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
	}
	else
		printf("Right walk into a Wall\n");
}
