
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

/** ----- CLOSE ----- **/
int			ft_close(t_cube *cube);
void		ft_free_array(char **array);

/** ----- PRINT ----- **/
void		db_print_array(char **array, char *msg);
void		ft_print_error(char *str);
void		ft_print_success(char *str);

/** ----- DEBUG ----- **/
void		db_print_file(int fd);
void		db_print_cube(t_cube *cube);

/** ----- MLX ----- **/
void		ft_init_mlx(t_cube *cube);
void		ft_handle_event(t_cube *cube);
void		ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int			ft_key_hook(int key, t_cube *cube);
int			ft_encode_rgb(uint8_t red, uint8_t green, uint8_t blue);

/** ----- PARSING ----- **/
int			ft_check_arguments(int ac, char **av);
void		ft_check_double(t_cube *cube, char *line);
t_cube		*ft_init_cube(int ac, char **av);
t_player	*ft_find_player(char **map);
void		ft_set_textures(t_cube *cube, int fd);
void		ft_set_wall(t_cube *cube, char *line);
void		ft_set_rgb(t_cube *cube, char *line);
void		ft_set_map(t_cube *cube, int fd);
void		ft_is_map_valid(t_cube *cube);

// List Map
t_list_map	*ft_lst_new_map(char *str);
void		ft_lst_addback_map(t_list_map **lst, t_list_map *nw);
void		ft_free_list_map(t_list_map *lst);
void		ft_print_list_map(t_list_map **lst);
size_t		ft_lst_len_map(t_list_map *lst);

char		**ft_cpy_map_utils(char **map);
bool		ft_is_valid_char_map_utils(char c);

/** ----- RENDER ----- **/
void		ft_floor_and_ceiling(t_cube *cube);
void		ft_minimap(t_cube *cube);
void		ft_render_next_frame(t_cube *cube);
void		ft_wall(t_cube *cube);

#endif
