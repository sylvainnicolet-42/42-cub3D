
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cube {
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_img	*img;
	struct s_img	*wall_n;
	struct s_img	*wall_s;
	struct s_img	*wall_e;
	struct s_img	*wall_w;
	char			**map;
	int				map_max_x;
	int				map_max_y;
	struct s_rgb	*f;
	struct s_rgb	*c;
	struct s_player	*player;
	bool			on_mouse;
	int				mouse_x;
	int				scene;
}					t_cube;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		*color;
}			t_img;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}					t_rgb;

typedef struct s_list_map {
	char				*str;
	struct s_list_map	*next;
}						t_list_map;

typedef struct s_player {
	unsigned int	pos_x;
	unsigned int	pos_y;
	float			plane_x;
	float			plane_y;
	float			facing;
	float			fov_start;
	struct s_real	*real;
	struct s_rgb	*color;
}					t_player;

typedef struct s_real {
	float	x;
	float	y;
}			t_real;

typedef struct s_wall_values {
	t_real	wall;
	t_real	distance;
	t_real	hypo;
	t_real	of7;
	float	dir;
}			t_wall_values;

typedef struct s_wall {
	t_real	pos;
	int		direction;
}			t_wall;

typedef struct s_pixel {
	t_real	wall;
	t_real	pos;
	int		height;
	int		color;
}			t_pixel;

#endif
