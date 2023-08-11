/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:47:59 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:48:01 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_strlen_max_x(char **str)
{
	int	i;
	int	len;
	int	max;

	i = 0;
	max = 0;
	while (str[i] != NULL)
	{
		len = (int) ft_strlen(str[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max - 1);
}

static int	ft_strlen_max_y(char **str)
{
	int	len;

	len = 0;
	while (str[len] != NULL)
		len++;
	return (len);
}

void	ft_find_max_value(t_cube *cube)
{
	cube->map_max_x = ft_strlen_max_x(cube->map);
	cube->map_max_y = ft_strlen_max_y(cube->map);
}
