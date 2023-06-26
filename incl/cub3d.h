
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
void		ft_check_double(t_cube *cube, char *line);
t_cube		*ft_init_cube(int ac, char **av);
void		ft_set_textures(t_cube *cube, int fd);
void		ft_set_wall(t_cube *cube, char *line);
void		ft_set_rgb(t_cube *cube, char *line);
void		ft_set_map(t_cube *cube, int fd);
void		ft_is_map_valid(t_matrix *matrix);

// List Map
t_list_map	*ft_lst_new_map(char *str);
void		ft_lst_addback_map(t_list_map **lst, t_list_map *nw);
void		ft_free_list_map(t_list_map *lst);
void		ft_print_list_map(t_list_map **lst);
size_t		ft_lst_len_map(t_list_map *lst);

/** ----- MLX ----- **/
void		ft_init_mlx(t_cube *cube);
void		ft_handle_event(t_cube *cube);
int			ft_key_hook(int key, t_cube *cube);

/** ----- PRINT ----- **/
void		db_print_array(char **array);
void		ft_print_error(char *str);
void		ft_print_success(char *str);

/** ----- CLOSE ----- **/
int			ft_close(t_cube *cube);
void		ft_free_array(char **array);

/** ----- DEBUG ----- **/
void		db_print_file(int fd);
void		db_print_cube(t_cube *cube);

#endif
