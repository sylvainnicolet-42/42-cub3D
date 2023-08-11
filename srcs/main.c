/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:43:39 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:43:42 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cube		*cube;

	cube = ft_init_cube(ac, av);
	db_print_cube(cube);
	ft_handle_event(cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
