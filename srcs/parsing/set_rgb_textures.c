
#include "cub3d.h"

static bool	ft_is_valid_identifier(char *line)
{
	if (ft_strncmp(line, "C ", 2) == 0 || ft_strncmp(line, "F ", 2) == 0)
		return (true);
	return (false);
}

static t_rgb	*ft_get_rgb(char *colors)
{
	char	**split;
	t_rgb	*rgb;

	split = ft_split(colors, ',');
	if (!split)
		ft_print_error(MSG_MALLOC_ERR);
	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		ft_print_error(MSG_MALLOC_ERR);
	ft_check_is_color_valid(split);
	rgb->r = ft_atoi(split[0]);
	rgb->g = ft_atoi(split[1]);
	rgb->b = ft_atoi(split[2]);
	ft_free_array(split);
	return (rgb);
}

static void	ft_set_color(t_cube *cube, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_print_error(MSG_MALLOC_ERR);
	ft_check_double(cube, split[0]);
	if (ft_strncmp(split[0], "C", 1) == 0)
		cube->ceiling = ft_get_rgb(split[1]);
	else if (ft_strncmp(split[0], "F", 1) == 0)
		cube->floor = ft_get_rgb(split[1]);
	ft_free_array(split);
}	

static bool	ft_is_color_set(t_cube *cube)
{
	if (cube->ceiling && cube->floor)
		return (true);
	return (false);
}

void	ft_set_rgb_textures(t_cube *cube, int fd)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd);
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		if (ft_is_valid_identifier(trimmed))
			ft_set_color(cube, trimmed);
		if (ft_is_color_set(cube))
		{
			free(line);
			free(trimmed);
			break ;
		}
		free(line);
		free(trimmed);
		line = get_next_line(fd);
	}
	if (ft_is_color_set(cube) == false)
		ft_print_error(MSG_RGB_NOT_SET_ERR);
}	
