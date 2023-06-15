/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:55:26 by synicole          #+#    #+#             */
/*   Updated: 2022/10/11 15:55:27 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	i = 0;
	if (s == 0 && d == 0)
		return (0);
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (i++ < len)
			d[i - 1] = s[i - 1];
	return (dst);
}
