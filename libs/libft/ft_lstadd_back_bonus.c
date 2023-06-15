/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:07:52 by synicole          #+#    #+#             */
/*   Updated: 2022/10/19 16:07:54 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_el;

	if (!*lst)
		*lst = new;
	else
	{
		current_el = *lst;
		while (current_el->next)
			current_el = current_el->next;
		current_el->next = new;
	}
}
