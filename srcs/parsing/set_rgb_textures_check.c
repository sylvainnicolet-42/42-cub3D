
#include "cub3d.h"

static void	ft_check_rgb_is_number(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[j] != NULL)
	{
		while (split[j][i] != '\0')
		{
			if (ft_isdigit(split[j][i]))
			{
				i++;
				continue ;
			}
			else
				ft_print_error(MSG_RGB_WRONG_ARG_ERR);
		}
		i = 0;
		j++;
	}
}

static void	ft_check_rgb_range(char **split)
{
	if (ft_atoi(split[0]) < 0 || ft_atoi(split[0]) > 255)
		ft_print_error(MSG_RGB_RANGE_ERR);
	if (ft_atoi(split[1]) < 0 || ft_atoi(split[1]) > 255)
		ft_print_error(MSG_RGB_RANGE_ERR);
	if (ft_atoi(split[2]) < 0 || ft_atoi(split[2]) > 255)
		ft_print_error(MSG_RGB_RANGE_ERR);
}

void	ft_check_is_color_valid(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[i] != NULL)
		i++;
	if (i != 3)
		ft_print_error(MSG_RGB_ARG_ERR);
	ft_check_rgb_is_number(split);
	ft_check_rgb_range(split);
}
