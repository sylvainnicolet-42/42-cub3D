
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
//		===== PARSING DIRECTORY =====
//###########################################//
//
//	----- Check_Arguments.c -----
void	check_arguments(int ac, char **av, t_cube *cube);

#endif
