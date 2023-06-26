
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cube {
	void			*mlx_ptr;
	void			*win_ptr;
	char			*path_wall_n;
	char			*path_wall_s;
	char			*path_wall_e;
	char			*path_wall_w;
	struct s_rgb	*floor;
	struct s_rgb	*ceiling;
	struct s_matrix	*matrix;
}					t_cube;

typedef struct s_matrix {
	char			**map;
	struct s_pos	*player;
}					t_matrix;

typedef struct s_rgb {
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct s_list_map {
	char				*str;
	struct s_list_map	*next;
}						t_list_map;

typedef struct s_pos {
	unsigned int	x;
	unsigned int	y;
}					t_pos;

#endif
