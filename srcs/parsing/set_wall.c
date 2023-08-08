
#include "cub3d.h"

static bool	ft_can_texture_be_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

static t_img	*ft_init_texture(t_cube *cube, char *path)
{
	t_img	*img;

	printf("path: %s\n", path);
	img = malloc(sizeof(t_img));
	if (!img)
		ft_print_error(MSG_MALLOC_ERR);
	img->img = mlx_xpm_file_to_image(cube->mlx_ptr, path, &img->width,
			&img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	return (img);
}

void	ft_set_wall(t_cube *cube, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_print_error(MSG_MALLOC_ERR);
	ft_check_double(cube, split[0]);
	if (ft_can_texture_be_open(split[1]) == false)
		ft_print_error(MSG_TEXTURES_CANT_OPEN_ERR);
	if (ft_strncmp(split[0], "NO", 2) == 0)
		cube->wall_n = ft_init_texture(cube, split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		cube->wall_s = ft_init_texture(cube, split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		cube->wall_w = ft_init_texture(cube, split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		cube->wall_e = ft_init_texture(cube, split[1]);
	ft_free_array(split);
}
