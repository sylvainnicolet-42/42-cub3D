
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
		cube->floor->r, cube->floor->g, cube->floor->b);
	printf("ceiling_RGB=> R[%d] G[%d] B[%d]\n",
		cube->ceiling->r, cube->ceiling->g, cube->ceiling->b);
	printf("\n");
}

void	db_print_array(char **array)
{
	int	i;

	printf("\n--- DEBUG: PRINT ARRAY ---\n");
	printf("--------------------------------\n");
	i = 0;
	while (array[i])
	{
		printf("[%d] => [%s]\n", i, array[i]);
		i++;
	}
	printf("\n");
}
