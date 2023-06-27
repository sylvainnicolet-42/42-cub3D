
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
