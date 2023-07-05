
#include "cub3d.h"

void	ft_render_next_frame(t_cube *cube)
{
	ft_floor_and_ceiling(cube);
	ft_wall(cube);
	ft_minimap(cube);
}
