/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:36:34 by synicole          #+#    #+#             */
/*   Updated: 2022/10/17 20:36:37 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	ft_countchar(const char *str, unsigned int index, char c)
{
	unsigned int	count;

	count = 0;
	while (str[index] != c && str[index] != '\0')
	{
		index++;
		count++;
	}
	return (count);
}

static int	ft_find_next_word(const char *str, unsigned int index, char c)
{
	while (str[index] != c && str[index] != '\0')
		index++;
	while (str[index] == c && str[index] != '\0')
		index++;
	return (index);
}

static char	**ft_fillarray(char **array, char const *s, char c, int nb_world)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	if (s[0] == c)
		start = ft_find_next_word(s, start, c);
	while (i < nb_world)
	{
		array[i] = ft_substr(s, start, ft_countchar(s, start, c));
		start = ft_find_next_word(s, start, c);
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		nb_world;

	nb_world = ft_countword(s, c);
	array = ft_calloc(nb_world + 1, sizeof(char *));
	if (!array)
		return (0);
	array = ft_fillarray(array, s, c, nb_world);
	return (array);
}
