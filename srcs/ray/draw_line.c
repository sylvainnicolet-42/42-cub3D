
#include "cub3d.h"

static float	get_max(float step_x, float step_y)
{
	float	abs_step_x;
	float	abs_step_y;
	float	max;

	if (step_x < 0)
		abs_step_x = -step_x;
	else
		abs_step_x = step_x;
	if (step_y < 0)
		abs_step_y = -step_y;
	else
		abs_step_y = step_y;
	if (abs_step_x > abs_step_y)
		max = abs_step_x;
	else
		max = abs_step_y;
	return (max);
}

void	ft_draw_line(t_cube *cube, t_real *wall, t_rgb *color)
{
	float	step_x;
	float	step_y;
	float	max;
	t_real	a;
	t_real	b;
	float	ratio_x;
	float	ratio_y;

	ratio_x = ((float)WIN_WIDTH / 2) / cube->map_max_x;
	ratio_y = (float)WIN_HEIGHT / cube->map_max_y;
	a.x = cube->player->real->x * ratio_x;
	a.y = cube->player->real->y * ratio_y;
	b.x = wall->x * ratio_x;
	b.y = wall->y * ratio_y;
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = get_max(step_x, step_y);
	step_x /= max;
	step_y /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		ft_mlx_pixel_put(cube->img, a.x, a.y, ft_encode_rgb(color->r, color->g, color->b));
		a.x += step_x;
		a.y += step_y;
	}
}
