/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:48:31 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:48:55 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Close the program
 * @param cube
 *
 * @return int
 */
static void	ft_free_cube(t_cube *cube)
{
	free(cube->wall_e->color);
	free(cube->wall_n->color);
	free(cube->wall_s->color);
	free(cube->wall_w->color);
	free(cube->door->color);
	free(cube->wall_e);
	free(cube->wall_n);
	free(cube->wall_s);
	free(cube->wall_w);
	free(cube->door);
	free(cube->f);
	free(cube->c);
	ft_free_array(cube->map);
	free(cube->player->real);
	free(cube->player->color);
	free(cube->player);
	free(cube->img);
	free(cube);
}

int	ft_close(t_cube *cube)
{
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	ft_free_cube(cube);
	ft_print_success(MSG_CLOSE_SUCCESS);
	return (0);
}
