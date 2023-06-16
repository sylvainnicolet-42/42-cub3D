
#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_cube {
	struct s_matrix	*matrix;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_cube;

typedef struct s_matrix {
	char			*path_texture_n;
	char			*path_texture_s;
	char			*path_texture_e;
	char			*path_texture_w;
	struct s_rgb	*floor;
	struct s_rgb	*ceiling;
}					t_matrix;

typedef struct s_rgb {
	char	r;
	char	g;
	char	b;
}			t_rgb;

#endif