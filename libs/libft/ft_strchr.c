/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:57:47 by synicole          #+#    #+#             */
/*   Updated: 2022/10/11 18:57:49 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	el;

	str = (unsigned char *) s;
	el = (unsigned char) c;
	while (*str)
	{
		if (*str == el)
			return ((char *) str);
		str++;
	}
	if (!el)
		return ((char *) str);
	return (0);
}
