
#include "cub3d.h"

static int	ft_rad_to_angle(float facing)
{
	int	angle;
	
	angle = (int)((360 / (2 * M_PI)) * facing);
	return (angle);
}

static float	ft_angle_to_rad(int angle)
{
	float	rad;

	rad = ((2 * M_PI) / 360) * angle;
	return (rad);
}

void	ft_print_fov(t_cube *cube)
{
	int		angle;
	int		i;

	angle = ft_rad_to_angle(cube->player->facing);
	angle -= 180;
	i = 0;
	while (i < 360)
	{
		if (angle < 0)
			angle = 360 + angle;
		else if (angle > 360)
			angle -= 360;
		printf("angle [%d] rad [%f]\n", angle, ft_angle_to_rad(angle));
		ft_print_ray(cube, angle, ft_angle_to_rad(angle));
		angle++;
		i++;
	}
}
