
#include "cub3d.h"

int	ft_mouse_hook(int x, int y, t_cube *cube)
{
	(void)y;
	if (cube->on_mouse == true)
	{
		printf("x = %d\n", x - cube->mouse_x);
		if (x - cube->mouse_x > 0)
			ft_move_vision_right(cube, D_LOOK_MOUSE);
		else if (x - cube->mouse_x < 0)
			ft_move_vision_left(cube, D_LOOK_MOUSE);
	}
	cube->mouse_x = x;
	return (0);
}

int	ft_mouse_press(int button, int x, int y, t_cube *cube)
{
	(void)button;
	if ((x > 0 && x < WIN_WIDTH) && (y > 0 && y < WIN_HEIGHT))
	{
		cube->mouse_x = x;
		cube->on_mouse = true;
	}
	return (0);
}

int	ft_mouse_release(int button, int x, int y, t_cube *cube)
{
	(void)button;
	(void)x;
	(void)y;
	cube->on_mouse = false;
	return (0);
}
