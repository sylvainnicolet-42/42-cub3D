
#include "cub3d.h"

static bool	ft_are_textures_set(t_cube *cube)
{
	if (cube->path_texture_n && cube->path_texture_s
		&& cube->path_texture_w && cube->path_texture_e)
		return (true);
	return (false);
}

static bool	ft_is_valid_identifier(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

static void	ft_check_texture(t_cube *cube)
{
	if (ft_are_textures_set(cube) == false)
		ft_print_error(MSG_TEXTURES_NOT_SET_ERR);
}

static void	ft_set_path(t_cube *cube, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_print_error(MSG_MALLOC_ERR);
	ft_check_double(cube, split[0]);
	if (ft_strncmp(split[0], "NO", 2) == 0)
		cube->path_texture_n = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		cube->path_texture_s = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		cube->path_texture_w = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		cube->path_texture_e = ft_strdup(split[1]);
	ft_free_array(split);
}

void	ft_set_textures(t_cube *cube, int fd)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		if (ft_is_valid_identifier(trimmed))
			ft_set_path(cube, trimmed);
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
	ft_check_texture(cube);
}
