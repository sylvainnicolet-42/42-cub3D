/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:40:44 by synicole          #+#    #+#             */
/*   Updated: 2022/10/14 21:40:46 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_start(char const *s1, char const *set)
{
	int	rm_start;
	int	i;
	int	j;

	rm_start = 0;
	i = 0;
	j = 0;
	while (set[i])
	{
		if (set[i] == s1[j])
		{
			rm_start++;
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (rm_start);
}

static int	ft_check_end(char const *s1, char const *set, size_t rm_start)
{
	size_t	rm_end;
	size_t	i;
	size_t	j;

	rm_end = 0;
	i = 0;
	j = ft_strlen(s1) - 1;
	while (set[i] && rm_start < ft_strlen(s1))
	{
		if (set[i] == s1[j])
		{
			rm_end++;
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (rm_end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	rm_start;
	size_t	rm_end;
	size_t	i;

	rm_start = ft_check_start(s1, set);
	rm_end = ft_check_end(s1, set, rm_start);
	ptr = ft_calloc(sizeof(char), (ft_strlen(s1) - rm_start - rm_end) + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < ft_strlen(s1) - rm_start - rm_end)
	{
		ptr[i] = s1[rm_start + i];
		i++;
	}
	return (ptr);
}
