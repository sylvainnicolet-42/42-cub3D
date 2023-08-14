/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:45:13 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:09:38 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	*ft_get_door_texture(t_cube *cube, char *path)
{
	t_img	*img;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_print_error(MSG_DOOR_TEX_CANT_OPEN_ERR);
	}
	close(fd);
	img = ft_init_texture(cube, path);
	return (img);
}

/**
 * Initialize the struct t_cube.
 * @param ac, av
 * @return cube
 */
t_cube	*ft_init_cube(int ac, char **av)
{
	int		fd;
	t_cube	*cube;

	fd = ft_check_arguments(ac, av);
	cube = malloc(sizeof(t_cube));
	if (!cube)
		ft_print_error(MSG_MALLOC_ERR);
	*cube = (t_cube){};
	cube->on_mouse = false;
	cube->scene = 1;
	ft_init_mlx(cube);
	ft_set_textures(cube, fd);
	ft_set_map(cube, fd);
	ft_is_map_valid(cube);
	ft_find_max_value(cube);
	cube->player = ft_find_player(cube->map);
	cube->door = ft_get_door_texture(cube, "textures/door/door.xpm");
	close(fd);
	return (cube);
}
