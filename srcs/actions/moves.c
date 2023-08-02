
#include "cub3d.h"

void	ft_move_forward(t_cube *cube)
{
	double	d_x;
	double	d_y;

	d_x = cos(cube->player->facing) * D_UNIT;
	d_y = sin(cube->player->facing) * D_UNIT;
	if (ft_collision_forw(cube->map, cube->player->real, d_x, d_y) == true)
	{
		cube->player->real->x += d_x;
		cube->player->real->y += d_y;
		printf("Move Forward\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
		printf("Player facing [%f]\n", cube->player->facing);
	}
	else
		printf("Forward walk into a Wall\n");
}

void	ft_move_backward(t_cube *cube)
{
	double	d_x;
	double	d_y;

	d_x = cos(cube->player->facing) * D_UNIT;
	d_y = sin(cube->player->facing) * D_UNIT;
	if (ft_collision_back(cube->map, cube->player->real, d_x, d_y) == true)
	{
		cube->player->real->x -= d_x;
		cube->player->real->y -= d_y;
		printf("Move Backward\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
		printf("Player facing [%f]\n", cube->player->facing);
	}
	else
		printf("Backward walk into a Wall\n");
}

void	ft_move_left(t_cube *cube)
{
	double	d_x;
	double	d_y;

	d_x = cos(cube->player->facing) * D_UNIT;
	d_y = sin(cube->player->facing) * D_UNIT;
	if (ft_collision_left(cube->map, cube->player->real, d_x, d_y) == true)
	{
		cube->player->real->x += d_y;
		cube->player->real->y -= d_x;
		printf("Move Left\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
		printf("Player facing [%f]\n", cube->player->facing);
	}
	else
		printf("Left walk into a Wall\n");
}

void	ft_move_right(t_cube *cube)
{
	double	d_x;
	double	d_y;

	d_x = cos(cube->player->facing) * D_UNIT;	// direction [x]
	d_y = sin(cube->player->facing) * D_UNIT;	// direction [y]
	if (ft_collision_right(cube->map, cube->player->real, d_x, d_y) == true)
	{
		cube->player->real->x -= d_y;
		cube->player->real->y += d_x;
		printf("Move Right\n");
		printf("Player pos y [%f]\n", cube->player->real->y);
		printf("Player pos x [%f]\n", cube->player->real->x);
		printf("Player facing [%f]\n", cube->player->facing);
	}
	else
		printf("Right walk into a Wall\n");
}
