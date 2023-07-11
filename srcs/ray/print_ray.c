
#include "cub3d.h"

static t_real	ft_next_wall(float facing, t_real pos, int dir, char **map)
{
	float	angle;
	float	distance_x;
	float	distance_y;
	t_real	wall;

	distance_y = -1;
	distance_x = -1;
	wall.y = -1;
	wall.x = -1;
	//distace to the next intersection in the axis y and x
	if (dir == E_SE)
	{
		angle = facing;
		distance_y = (int)pos.y + 1 - pos.y;	// go + in y
		distance_x = (int)pos.x + 1 - pos.x;	// go + in x
	}
	else if (dir == E_SW)
	{
		angle = M_PI - facing;
		distance_y = (int)pos.y + 1 - pos.y;	// go + in y
		distance_x = pos.x - (int)pos.x;		// go - in x
	}
	else if (dir == E_NW)
	{
		angle = facing - M_PI;
		distance_y = pos.y - (int)pos.y;		// go - in y
		distance_x = pos.x - (int)pos.x;		// go - in x
	}
	if (dir == E_NE)
	{
		angle = (2 * M_PI) - facing;
		distance_y = pos.y - (int)pos.y;		// go - in y
		distance_x = (int)pos.x + 1 - pos.x;	// go + in x
	}
	printf("distance y[%f]\n", distance_y);
	printf("distance x[%f]\n", distance_x);
	printf("angle [%f]\n", angle);
	
	// loop to check each intersection and if there is a wall
	float	hypo_x;
	float	hypo_y;

	//calculating the hypotenus of the triangle axis y and x
	hypo_y = distance_y / sin(angle);
	hypo_x = distance_x / cos(angle);
	printf("hypo_y[%f]\n", hypo_y);
	printf("hypo_x[%f]\n", hypo_x);
	if (hypo_x < hypo_y)
	{
		if (dir == E_SE)
		{
			printf("hypo_x SE\n");
			wall.y = pos.y + (distance_x * tan(angle));
			wall.x = pos.x + distance_x;
			if (map[(int)pos.y][(int)pos.x + 1] == '1')
				printf("this is a wall\n");
		}
		else if (dir == E_SW)
		{
			printf("hypo_x SW\n");
			wall.y = pos.y + (distance_x * tan(angle));
			wall.x = pos.x - distance_x;
			if (map[(int)pos.y][(int)pos.x - 1] == '1')
				printf("this is a wall\n");
		}
		else if (dir == E_NW)
		{
			printf("hypo_x NW\n");
			wall.y = pos.y - (distance_x * tan(angle));
			wall.x = pos.x - distance_x;
			if (map[(int)pos.y][(int)pos.x - 1] == '1')
				printf("this is a wall\n");
		}
		else if (dir == E_NE)
		{
			printf("hypo_x NE\n");
			wall.y = pos.y - (distance_x * tan(angle));
			wall.x = pos.x + distance_x;
			if (map[(int)pos.y][(int)pos.x + 1] == '1')
				printf("this is a wall\n");
		}
	}
	else if (hypo_y < hypo_x)
	{
		if (dir == E_SE )
		{
			printf("hypo_y SE\n");
			wall.y = pos.y + distance_y;
			wall.x = pos.x + (distance_y / tan(angle));
			if (map[(int)pos.y + 1][(int)pos.x] == '1')
				printf("this is a wall\n");
		}
		else if (dir == E_SW)
		{
			printf("hypo_y SW\n");
			wall.y = pos.y + distance_y;
			wall.x = pos.x - (distance_y / tan(angle));
			if (map[(int)pos.y + 1][(int)pos.x] == '1')
				printf("this is a wall\n");
		}
		else if (dir == E_NW)
		{
			printf("hypo_y NW\n");
			wall.y = pos.y - distance_y;
			wall.x = pos.x - (distance_y / tan(angle));
			if (map[(int)pos.y - 1][(int)pos.x] == '1')
				printf("this is a wall\n");
		}
		else if (dir == E_NE)
		{
			printf("hypo_y NE\n");
			wall.y = pos.y - distance_y;
			wall.x = pos.x + (distance_y / tan(angle));
			if (map[(int)pos.y - 1][(int)pos.x] == '1')
				printf("this is a wall\n");
		}
	}
	printf("wall y[%f]\n", wall.y);
	printf("wall x[%f]\n", wall.x);
	return (wall);
}

void	ft_print_ray(t_cube *cube, float facing)
{
	t_real	facing_axis;
	int		dir;
	/*
	 * First thing first we have to know in wich direction the player is looking
	 * like this we can know how we want to move in the axis x and y
	 */
	if (facing == M_PI_2)
	{
		facing_axis.y = 0;
		dir = E_N;
	}
	else if (facing == (3 * M_PI) / 2)
	{
		facing_axis.y = 0;
		printf("Looking South\n");
		dir = E_S;
	}
	else if (facing > 0 && facing < M_PI )
		facing_axis.y = 1;
	else if (facing > M_PI && facing < 2 * M_PI)
		facing_axis.y = -1;
	if	(facing == M_PI)
	{
		dir = E_W;
		printf("Looking West\n");
		facing_axis.x = 0;
	}
	else if (facing == 0 || facing == M_PI * 2)
	{
		dir = E_E;
		printf("Looking East\n");
		facing_axis. x = 0;
	}
	else if ((facing > (3 * M_PI) / 2 && facing < 2 * M_PI) || 
		(facing > 0 && facing < M_PI_2))
		facing_axis.x = 1;
	else if (facing > M_PI_2  && facing < (3 * M_PI) / 2)
		facing_axis.x = -1;
	if (facing_axis.y == -1 && facing_axis.x == 1)
	{
		dir = E_NE;
		printf("Loking North East\n");
	}
	else if (facing_axis.y == -1 && facing_axis.x == -1)
	{
		dir = E_NW;
		printf("Loking North West\n");
	}
	else if (facing_axis.y == 1 && facing_axis.x == -1)
	{
		dir = E_SW;
		printf("Loking South West\n");
	}
	else if (facing_axis.y == 1 && facing_axis.x == 1)
	{
		dir = E_SE;
		printf("Loking South East\n");
	}
	/*
	 * We now know how in wich direction the player is looking
	 *
	 * After we need to know the distance to the next tile by the axis x
	 * and by the axis y
	 *
	 * If the distance to the next tile in the axis x -> [15 len] is greater 
	 * than the axis y -> [5 len] 
	 * 
	 * We need now to check if the next tile in the axis y is a wall or not
	 *
	 * If it's not a wall we have to proced to the same check as before to find
	 * a wall
	 */

	t_real	pos;
	t_rgb	color;
	color.r = 0;
	color.g = 0;
	color.b = 255;

	pos = ft_next_wall(facing, *cube->player->real, dir, cube->map);
//	printf("pos.y[%f], pos.x[%f]\n", pos.y, pos.x);
	ft_draw_cube(cube, &pos, 0.05, &color); 
}
