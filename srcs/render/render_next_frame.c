
#include "cub3d.h"

//static int	ft_get_pixel(t_img *img, int x, int y, int line_length)
//{
//	int color;
//
////	printf("line_length = %d\n", line_length);
//	x = (y * line_length) + (x * 4);
////	printf("x = %d\n", x);
//	color = ft_encode_rgb(img->addr[x], img->addr[x + 1], img->addr[x + 2]);
//	return (color);
//}

//void	ft_print_texture(t_cube *cube)
//{
//	int		x;
//	int		y;
//	t_img	*img;
//
//	img = malloc(sizeof(t_img));
//	img->img = mlx_xpm_file_to_image(cube->mlx_ptr, cube->path_wall_n, &x, &y);
//	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
//								  &img->line_length, &img->endian);
////	x= 0;
//	printf("line_length = %d\n", img->line_length);
//	while(x >= 0)
//	{
//		y = 176;
//		while (y >= 0)
//		{
//			ft_mlx_pixel_put(cube->img ,x, y, ft_get_pixel(img, x, y,img->line_length));
//			y--;
//		}
//		x--;
//	}
////	while (x < 176)
////	{
////		y = 0;
////		while (y < 176)
////		{
////		//	printf("x = %d, y = %d\n", x, y);
////			mlx_pixel_put(cube->mlx_ptr, cube->win_ptr, x, y, ft_get_pixel(img->img, x, y,img->line_length));
//////			ft_mlx_pixel_put(cube->img, x, y, ft_encode_rgb(255, 0, 0));
////			y++;
////		}
////		x++;
////	}
//}

int	ft_render_next_frame(t_cube *cube)
{
	ft_floor_and_ceiling(cube);
	if (cube->scene == 2)
	{
		ft_minimap(cube);
		ft_print_player(cube);
	}
	ft_print_fov(cube);
	ft_print_wall(cube, cube->player->fov_start);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	return (0);
}
