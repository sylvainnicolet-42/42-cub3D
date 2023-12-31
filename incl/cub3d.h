/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:50:20 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/14 13:32:14 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/** ----- LIBRARIES ----- **/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "../libs/libmlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include "define.h"
# include "enum.h"
# include "struct.h"

/** ----- ACTIONS ----- **/
bool		ft_collision_forw(char **map, t_real *real, float d_x, float d_y);
bool		ft_collision_back(char **map, t_real *real, float d_x, float d_y);
bool		ft_collision_left(char **map, t_real *real, float d_x, float d_y);
bool		ft_collision_right(char **map, t_real *real, float d_x, float d_y);
void		ft_move_vision_left(t_cube *cube, int look);
void		ft_move_vision_right(t_cube *cube, int look);
void		ft_move_forward(t_cube *cube);
void		ft_move_backward(t_cube *cube);
void		ft_move_left(t_cube *cube);
void		ft_move_right(t_cube *cube);
void		ft_open_door(t_cube *cube);

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
int			ft_key_hook_linux(int key, t_cube *cube);
int			ft_key_hook(int key, t_cube *cube);
int			ft_encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue);
int			ft_mouse_hook(int x, int y, t_cube *cube);
int			ft_mouse_press(int button, int x, int y, t_cube *cube);
int			ft_mouse_release(int button, int x, int y, t_cube *cube);

/** ----- PARSING ----- **/
int			ft_check_arguments(int ac, char **av);
void		ft_check_double(t_cube *cube, char *line);
t_cube		*ft_init_cube(int ac, char **av);
void		ft_find_max_value(t_cube *cube);
t_player	*ft_find_player(char **map);
void		ft_set_textures(t_cube *cube, int fd);
t_img		*ft_init_texture(t_cube *cube, char *path);
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
void		ft_fill_one_map_utils(char **map);

/** ----- RAY ----- **/
void		ft_draw_line(t_cube *cube, t_real *wall, t_rgb *color);
int			ft_rad_to_angle(float facing);
float		ft_angle_to_rad(int angle);
void		ft_print_fov(t_cube *cube);
t_wall		ft_get_wall(t_cube *cube, float rad);
t_wall		ft_next_wall_e(t_real pos, char **map);
t_wall		ft_next_wall_s(t_real pos, char **map);
t_wall		ft_next_wall_w(t_real pos, char **map);
t_wall		ft_next_wall_n(t_real pos, char **map);
t_wall		ft_next_wall_se(float rad, t_real pos, char **map, t_cube *cube);
t_wall		ft_next_wall_sw(float rad, t_real pos, char **map, t_cube *cube);
t_wall		ft_next_wall_nw(float rad, t_real pos, char **map, t_cube *cube);
t_wall		ft_next_wall_ne(float rad, t_real pos, char **map, t_cube *cube);
t_wall		ft_mathias(char **map, t_real *pos, \
				t_wall_values *w, const float *rad);

/** ----- RENDER ----- **/
void		ft_floor_and_ceiling(t_cube *cube);
void		ft_minimap(t_cube *cube);
void		ft_print_player(t_cube *cube);
void		ft_draw_cube(t_cube *cube, t_real *real, float size, t_rgb *rgb);
t_img		*ft_get_img(t_wall wall, t_cube *cube);
float		ft_get_distance(t_cube *cube, t_wall wall, float rad);
void		ft_print_wall(t_cube *cube, float rad);
int			ft_render_next_frame(t_cube *cube);

#endif
