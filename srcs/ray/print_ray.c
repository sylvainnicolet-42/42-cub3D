
#include "cub3d.h"

void	ft_print_ray(t_cube *cube, float facing)
{
	/*
	 * First thing first we have to know in wich direction the player is looking
	 * like this we can know how we want to move in the axis x and y
	 */
	if (facing >= 0 && facing < M_PI)
		printf("Looking South\n");
	if (facing >= M_PI && facing <= 2 * M_PI)
		printf("Looking North\n");
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
	(void) cube;
}
