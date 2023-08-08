
#include "cub3d.h"

static int	ft_is_valid_identifier(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (E_WALL);
	else if (ft_strncmp(line, "C ", 2) == 0 || ft_strncmp(line, "F ", 2) == 0)
		return (E_RGB);
	return (0);
}

static bool	ft_are_textures_set(t_cube *cube)
{
	if (cube->wall_e && cube->wall_n && cube->wall_s
		&& cube->wall_w && cube->f && cube->c)
		return (true);
	return (false);
}

void	ft_set_textures(t_cube *cube, int fd)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		if (ft_is_valid_identifier(trimmed) == E_WALL)
			ft_set_wall(cube, trimmed);
		if (ft_is_valid_identifier(trimmed) == E_RGB)
			ft_set_rgb(cube, trimmed);
		if (ft_are_textures_set(cube))
		{
			free(trimmed);
			free(line);
			break ;
		}
		free(trimmed);
		free(line);
		line = get_next_line(fd);
	}
	if (ft_are_textures_set(cube) == false)
		ft_print_error(MSG_TEXTURES_NOT_SET_ERR);
}
