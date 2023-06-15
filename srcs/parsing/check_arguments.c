
#include "cub3d.h"

/*
 * Will check if the file has been opened
 */

static bool	is_map_open(int fd)
{
	if (fd == -1)
	{
		close (fd);
		return (false);
	}
	else
		return (true);
}

/*
 * Will check if the file finish by a ".rt"
 */

static bool	is_file_rt(char *str)
{
	if (ft_strlen(str) < 4)
		return (false);
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".cub", 4) == 0)
		return (true);
	return (false);
}

/*
 * TRUE arguments are valid
 * FALSE arguments are not valid
 */

void	check_arguments(int ac, char **av, t_cube *cube)
{
	int	fd;

	(void) cube;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		ft_print_error("Wrong Number of arguments");
	if (is_map_open(fd) == false)
		ft_print_error("Map can not be opend");
	if (is_file_rt(av[1]) == false)
		ft_print_error("Map is not a .cub");
}
