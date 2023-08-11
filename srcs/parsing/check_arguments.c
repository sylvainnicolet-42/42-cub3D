/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:48:07 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:48:09 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
 * @return int fd, the file descriptor of the map
 */
int	ft_check_arguments(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		ft_print_error(MSG_ARG_ERR);
	if (ft_is_file_cube(av[1]) == false)
		ft_print_error(MSG_FILE_NOT_CUB_ERR);
	fd = open(av[1], O_RDONLY);
	if (ft_is_map_open(fd) == false)
		ft_print_error(MSG_OPEN_FILE_ERR);
	return (fd);
}
