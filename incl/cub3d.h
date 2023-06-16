
#ifndef CUB3D_H
# define CUB3D_H

/** ----- LIBRARIES ----- **/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libs/libmlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include "define.h"
# include "enum.h"
# include "struct.h"

/** ----- PARSING ----- **/
int			ft_check_arguments(int ac, char **av);
t_cube		*ft_init_cube(int ac, char **av);
t_matrix	*ft_init_matrix(int ac, char **av);
void		ft_set_textures(t_cube *cube, int fd);

/** ----- MLX ----- **/
void		ft_init_mlx(t_cube *cube);
void		ft_handle_event(t_cube *cube);
int			ft_key_hook(int key, t_cube *cube);

/** ----- PRINT ----- **/
void		ft_print_error(char *str);
void		ft_print_success(char *str);

/** ----- CLOSE ----- **/
int			ft_close(t_cube *cube);
void		ft_free_array(char **array);

/** ----- DEBUG ----- **/
void		db_print_file(int fd);
void		db_print_cube(t_cube *cube);

#endif
