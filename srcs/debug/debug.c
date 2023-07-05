
#include "cub3d.h"

void	db_print_file(int fd)
{
	char	*line;

	printf("\n--- DEBUG: PRINT FILE ---\n");
	printf("--------------------------------\n");
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	db_print_cube(t_cube *cube)
{
	printf("\n--- DEBUG: PRINT CUBE ---\n");
	printf("--------------------------------\n");
	printf("path_texture_n => [%s]\n", cube->path_wall_n);
	printf("path_texture_s => [%s]\n", cube->path_wall_s);
	printf("path_texture_w => [%s]\n", cube->path_wall_w);
	printf("path_texture_e => [%s]\n", cube->path_wall_e);
	printf("floor_RGB => R[%d] G[%d] B[%d]\n",
		cube->f->r, cube->f->g, cube->f->b);
	printf("ceiling_RGB=> R[%d] G[%d] B[%d]\n",
		cube->c->r, cube->c->g, cube->c->b);
	printf("\n");
	printf("Position of player x[%d] y[%d]\n", cube->player->pos_x,
		cube->player->pos_y);
	printf("Direction of player x[%d] y[%d]\n", cube->player->dir_x,
		cube->player->dir_y);
	printf("Plane of player x[%f] y[%f]\n", cube->player->plane_x,
		cube->player->plane_y);
	db_print_array(cube->map, "MAP");
}

void	db_print_array(char **array, char *msg)
{
	int	i;

	printf("\n--- DEBUG: PRINT ARRAY : %s ---\n", msg);
	printf("--------------------------------\n");
	i = 0;
	while (array[i])
	{
		printf("[%d] =>	[%s]\n", i + 1, array[i]);
		i++;
	}
	printf("\n");
}
