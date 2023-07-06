
#include "cub3d.h"

char	**ft_cpy_map_utils(char **map)
{
	unsigned int	y;
	char			**map_cpy;

	y = 0;
	while (map[y] != NULL)
		y++;
	map_cpy = ft_calloc(sizeof(char *), y + 1);
	if (!map_cpy)
		ft_print_error(MSG_MALLOC_ERR);
	y = 0;
	while (map[y] != NULL)
	{
		map_cpy[y] = ft_strdup(map[y]);
		if (!map_cpy[y])
			ft_print_error(MSG_MALLOC_ERR);
		y++;
	}
	return (map_cpy);
}

bool	ft_is_valid_char_map_utils(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static char	*ft_fill_one_ext(char *map, int max)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_calloc(sizeof(char), max + 1);
	while (map[i] != '\0')
	{
		tmp[i] = map[i];
		i++;
	}
	while (i < max)
		tmp[i++] = '1';
	free(map);
	return (tmp);
}

void	ft_fill_one_map_utils(char **map)
{
	int		y;
	int		max;
	int		len;

	y = 0;
	max = 0;
	len = 0;
	while (map[y] != NULL)
	{
		len = ft_strlen(map[y]);
		if (len > max)
			max = len;
		y++;
	}
	y = 0;
	while (map[y] != NULL)
	{
		if (ft_strlen(map[y]) != (size_t)max)
			map[y] = ft_fill_one_ext(map[y], max);
		y++;
	}
}
