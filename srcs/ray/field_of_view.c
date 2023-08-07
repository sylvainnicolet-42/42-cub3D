
#include "cub3d.h"

int	ft_rad_to_angle(float facing)
{
	int	angle;

	angle = (int)((360 / (2 * M_PI)) * facing);
	return (angle);
}

float	ft_angle_to_rad(int angle)
{
	float	rad;

	rad = ((2 * M_PI) / 360) * angle;
	return (rad);
}

void	ft_print_fov(t_cube *cube)
{
	t_real	wall;
	int		angle;
	int		i;
	t_rgb	color;

	color.r = 0;
	color.g = 0;
	color.b = 255;
	angle = ft_rad_to_angle(cube->player->facing);
	angle -= D_FOV / 2;
	if (angle < 0)
		angle += 360;
	cube->player->fov_start = ft_angle_to_rad(angle);
	i = 0;
	while (i < D_FOV)
	{
		if (angle < 0)
			angle += 360;
		else if (angle > 360)
			angle -= 360;
		wall = ft_get_wall(cube, angle, ft_angle_to_rad(angle));
		angle++;
		i++;
		ft_draw_line(cube, &wall, &color);
	}
}
