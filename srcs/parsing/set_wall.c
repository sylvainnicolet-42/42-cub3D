
#include "cub3d.h"

void	ft_set_wall(t_cube *cube, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_print_error(MSG_MALLOC_ERR);
	ft_check_double(cube, split[0]);
	if (ft_strncmp(split[0], "NO", 2) == 0)
		cube->path_wall_n = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		cube->path_wall_s = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		cube->path_wall_w = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		cube->path_wall_e = ft_strdup(split[1]);
	ft_free_array(split);
}
