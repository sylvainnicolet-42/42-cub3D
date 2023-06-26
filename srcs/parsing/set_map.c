
#include "cub3d.h"

static void	ft_is_map_empty(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
		ft_print_error(MSG_MAP_NOT_EMPTY_ERR);
}

static bool	ft_is_map(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\0')
		return (false);
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			ft_print_error(MSG_MAP_NOT_VALID_ERR);
		i++;
	}
	return (true);
}

static t_matrix	*ft_set_matrix(t_list_map *lst)
{
	t_matrix	*matrix;
	size_t		len_map;
	t_list_map	*node;
	int			i;

	i = 0;
	len_map = ft_lst_len_map(lst);
	node = lst;
	matrix = malloc(sizeof(t_matrix));
	if (!matrix)
		ft_print_error(MSG_MALLOC_ERR);
	matrix->map = ft_calloc(sizeof(char *), len_map + 1);
	if (!matrix->map)
		ft_print_error(MSG_MALLOC_ERR);
	while (node != NULL)
	{
		matrix->map[i] = ft_strdup(node->str);
		if (!matrix->map[i])
			ft_print_error(MSG_MALLOC_ERR);
		i++;
		node = node->next;	
	}
	return (matrix);
}

void	ft_set_map(t_cube *cube, int fd)
{
	t_list_map	*map;
	char		*line;
	char		*trimmed;
	bool		map_found;

	line = get_next_line(fd);
	map = NULL;
	map_found = false;
	while (line)
	{
		trimmed = ft_strtrim(line, "\n");
		ft_check_double(cube, trimmed);
		if (ft_is_map(trimmed) == true)
		{
			map_found = true;
			ft_lst_addback_map(&map, ft_lst_new_map(trimmed));
		}
		else 
		{
			if (map_found == true)
			{
				free(line);
				free(trimmed);
				ft_print_error(MSG_MAP_NOT_EMPTY_ERR);
			}
		}
		free(line);
		free(trimmed);
		line = get_next_line(fd);
	}
	cube->matrix = ft_set_matrix(map);
	ft_free_list_map(map);
	ft_is_map_empty(fd);
}
