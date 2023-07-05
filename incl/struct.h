
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cube {
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_img	*img;
	char			*path_wall_n;
	char			*path_wall_s;
	char			*path_wall_e;
	char			*path_wall_w;
	char			**map;
	int				map_max_x;
	int				map_max_y;
	struct s_rgb	*f;
	struct s_rgb	*c;
	struct s_player	*player;
}					t_cube;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_rgb {
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct s_list_map {
	char				*str;
	struct s_list_map	*next;
}						t_list_map;

typedef struct s_player {
	unsigned int	pos_x;
	unsigned int	pos_y;
	unsigned int	real_x;
	unsigned int	real_y;
	int				dir_x;
	int				dir_y;
	float			plane_x;
	float			plane_y;
}					t_player;

#endif
