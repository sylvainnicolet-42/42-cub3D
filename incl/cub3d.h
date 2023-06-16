
#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# include "../libs/libmlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include "struct.h"
# include "define.h"

//###########################################//
//		===== CLOSE DIRECTORY =====
//###########################################//
//
//	----- Close.c -----
int			ft_close(t_cube *cube);

//	----- Print.c -----
void		ft_print_error(char *str);
void		ft_print_success(char *str);

//###########################################//
//		===== MLX DIRECTORY =====
//###########################################//
//
//	----- Init_MLX.c -----
void		ft_init_mlx(t_cube *cube);
void		ft_handle_event(t_cube *cube);
int			ft_key_hook(int key, t_cube *cube);

//###########################################//
//		===== PARSING DIRECTORY =====
//###########################################//
//
//	----- Check_Arguments.c -----
void		ft_check_arguments(int ac, char **av);

//	----- Init_Cube.c -----
t_cube		*ft_init_cube(t_matrice *matrice);

//	----- Init_Matrix.c -----
t_matrice	*ft_init_matrice(int ac, char **av);

#endif
