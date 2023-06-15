
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
//	----- Free.c -----
void	ft_free_all(t_cube *cube);

//	----- Print.c -----
void	ft_print_error(char *str);
void	ft_print_success(char *str);

//###########################################//
//		===== PARSING DIRECTORY =====
//###########################################//
//
//	----- Check_Arguments.c -----
void	ft_check_arguments(int ac, char **av);

//	----- Init_Cube.c -----
void	ft_init_cube(int ac, char **av, t_cube *cube);

#endif
