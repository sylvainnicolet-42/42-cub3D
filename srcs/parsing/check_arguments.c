
#include "cub3d.h"

/**
 * Will check if the map can be opened
 * @param fd
 *
 * @return bool, true if the map can be opened, false if not
 */
static bool	ft_is_map_open(int fd)
{
	if (fd == -1)
	{
		close (fd);
		return (false);
	}
	else
		return (true);
}

/**
 * Will check if the map is a .cub
 * @param str
 *
 * @return bool, true if the map is a .cub, false if not
 */
static bool	ft_is_file_cube(char *str)
{
	if (ft_strlen(str) < 4)
		return (false);
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".cub", 4) == 0)
		return (true);
	return (false);
}

/**
 * Will check if the arguments are valid and if the map can be opened
 * @param ac
 * @param av
 * @param cube
 *
 * @return void
 */
void	ft_check_arguments(int ac, char **av, t_cube *cube)
{
	int	fd;

	(void) cube;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		ft_print_error("Wrong Number of arguments");
	if (ft_is_map_open(fd) == false)
		ft_print_error("Map can not be opend");
	if (ft_is_file_cube(av[1]) == false)
		ft_print_error("Map is not a .cub");
}
