/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:48:36 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/11 14:48:39 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Print error message and exit program
 * @param str error message
 *
 * @return void
 */
void	ft_print_error(char *str)
{
	printf("\033[0;31m");
	printf("Error\n");
	printf("Reason: %s\n", str);
	exit(EXIT_FAILURE);
}

/**
 * Print success message and exit program
 * @param str success message
 *
 * @return void
 */
void	ft_print_success(char *str)
{
	printf("\033[0;32m");
	printf("Success: %s\n", str);
	exit(EXIT_SUCCESS);
}
