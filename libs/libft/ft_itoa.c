/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:30:04 by synicole          #+#    #+#             */
/*   Updated: 2022/10/16 20:30:09 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlength(int n)
{
	int	length;

	length = 1;
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n >= 10)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*ft_putnbr(int n, char *ptr, int i)
{
	if (n == -2147483648)
		return ("-2147483648");
	else
	{
		if (n < 0)
		{
			ptr[0] = '-';
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10, ptr, i - 1);
		ptr[i] = n % 10 + '0';
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		length;

	if (n == -2147483648)
	{
		ptr = ft_substr("-2147483648", 0, 11);
		if (!ptr)
			return (0);
		return (ptr);
	}
	length = ft_getlength(n);
	ptr = ft_calloc(sizeof(char), length + 1);
	if (!ptr)
		return (0);
	return (ft_putnbr(n, ptr, length - 1));
}
