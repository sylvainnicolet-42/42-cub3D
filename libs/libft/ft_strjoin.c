/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:07:03 by synicole          #+#    #+#             */
/*   Updated: 2022/10/14 21:07:04 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	length;
	size_t	i;
	size_t	j;

	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < (size_t) ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < (size_t) ft_strlen(s2))
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
