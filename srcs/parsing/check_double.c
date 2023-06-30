
#include "cub3d.h"

void	ft_check_double(t_cube *cube, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 && cube->path_wall_n != NULL)
		ft_print_error(MSG_TEXTURES_HAVE_DOUBLE_ERR);
	if (ft_strncmp(line, "SO", 2) == 0 && cube->path_wall_s != NULL)
		ft_print_error(MSG_TEXTURES_HAVE_DOUBLE_ERR);
	if (ft_strncmp(line, "WE", 2) == 0 && cube->path_wall_w != NULL)
		ft_print_error(MSG_TEXTURES_HAVE_DOUBLE_ERR);
	if (ft_strncmp(line, "EA", 2) == 0 && cube->path_wall_e != NULL)
		ft_print_error(MSG_TEXTURES_HAVE_DOUBLE_ERR);
	if (ft_strncmp(line, "C", 1) == 0 && cube->ceiling != NULL)
		ft_print_error(MSG_TEXTURES_HAVE_DOUBLE_ERR);
	if (ft_strncmp(line, "F", 1) == 0 && cube->floor != NULL)
		ft_print_error(MSG_TEXTURES_HAVE_DOUBLE_ERR);
}