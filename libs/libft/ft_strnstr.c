/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:15:48 by synicole          #+#    #+#             */
/*   Updated: 2022/10/13 19:15:50 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*to_find;
	char	*str;

	to_find = (char *) needle;
	str = (char *) haystack;
	i = 0;
	if (!*to_find)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < len)
		{
			if (!to_find[j + 1])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
