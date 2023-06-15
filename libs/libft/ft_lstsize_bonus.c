/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:53:48 by synicole          #+#    #+#             */
/*   Updated: 2022/10/19 14:53:52 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_el;
	int		size;

	current_el = lst;
	if (!current_el)
		return (0);
	size = 1;
	while (current_el->next)
	{
		current_el = current_el->next;
		size++;
	}
	return (size);
}
