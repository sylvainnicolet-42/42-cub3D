
#include "cub3d.h"

void	ft_print_player(t_cube *cube)
{
	float	ratio_x;
	float	ratio_y;
	float	x;
	float	y;

	ratio_x = ((float)WIN_WIDTH / 2) / cube->map_max_x;
	ratio_y = (float)WIN_HEIGHT / cube->map_max_y;
	x = (cube->player->real_x - D_PLAYER_SCALE) * ratio_x;
	y = (cube->player->real_y - D_PLAYER_SCALE) * ratio_y;
	while (y < (cube->player->real_y + D_PLAYER_SCALE) * ratio_y)
	{
		while (x < (cube->player->real_x + D_PLAYER_SCALE) * ratio_x)
		{
			ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(255, 0, 0));
			x++;
		}
		x = (cube->player->real_x - D_PLAYER_SCALE) * ratio_x;
		y++;
	}
}
