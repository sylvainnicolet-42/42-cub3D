
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

static void	ft_check_is_color_valid(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	if (i != 3)
		ft_print_error(MSG_RGB_ARG_ERR);
	ft_check_rgb_is_number(split);
	ft_check_rgb_range(split);
}

static t_rgb	*ft_get_rgb(char *colors)
{
	char	**split;
	t_rgb	*rgb;

	split = ft_split(colors, ',');
	if (!split)
		ft_print_error(MSG_MALLOC_ERR);
	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		ft_print_error(MSG_MALLOC_ERR);
	ft_check_is_color_valid(split);
	rgb->r = ft_atoi(split[0]);
	rgb->g = ft_atoi(split[1]);
	rgb->b = ft_atoi(split[2]);
	ft_free_array(split);
	return (rgb);
}

void	ft_set_rgb(t_cube *cube, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_print_error(MSG_MALLOC_ERR);
	ft_check_double(cube, split[0]);
	if (ft_strncmp(split[0], "C", 1) == 0)
		cube->c = ft_get_rgb(split[1]);
	else if (ft_strncmp(split[0], "F", 1) == 0)
		cube->f = ft_get_rgb(split[1]);
	ft_free_array(split);
}	
