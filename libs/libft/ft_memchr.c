/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:05:36 by synicole          #+#    #+#             */
/*   Updated: 2022/10/13 16:05:37 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	el;
	size_t			i;

	str = (unsigned char *) s;
	el = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*str == el)
			return (str);
		str++;
		i++;
	}
	return (0);
}
