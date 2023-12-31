/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:50:23 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 14:20:26 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/** ----- DEFINE ----- **/
# define PROG_NAME "Cub3D"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define D_UNIT 0.2
# define D_PLAYER_SCALE 0.2
# define D_FOV 45
# define D_LOOK_ARROW 5
# define D_LOOK_MOUSE 2
# define D_LINUX 0
# define D_EAST 0.000000
# define D_SOUTH 1.570796
# define D_WEST 3.141592
# define D_NORTH 4.712388

/** ----- SUCCESS MESSAGES ----- **/
# define MSG_CLOSE_SUCCESS "Cub3D ended successfully! 🚀"

/** ----- ERROR MESSAGES ----- **/
# define MSG_MALLOC_ERR "Malloc failed!"
# define MSG_ARG_ERR "Wrong Number of arguments"
# define MSG_OPEN_FILE_ERR "File can't be opened!"
# define MSG_FILE_NOT_CUB_ERR "File is not a .cub"

# define MSG_TEXTURES_NOT_SET_ERR "Textures are not set"
# define MSG_TEXTURES_CANT_OPEN_ERR "Textures can't be opened"
# define MSG_TEXTURES_NOT_SQUARE_ERR "Textures is not square"
# define MSG_DOOR_TEX_CANT_OPEN_ERR "Texture of door can't be opened"

# define MSG_RGB_RANGE_ERR "Value of the RGB is not in the range [0 - 255]"
# define MSG_RGB_ARG_ERR "Need 3 numbers for the RGB set"
# define MSG_RGB_WRONG_ARG_ERR "Value of rgb need to be a number"

# define MSG_MAP_NOT_VALID_ERR "Char in the map are not valid"
# define MSG_MAP_NOT_EMPTY_ERR "Map is not valid, no new line after the map"
# define MSG_MAP_NOT_CLOSE_ERR "Map is not close"

# define MSG_TWO_PLAYER_ERR "Map contain more than one player"
# define MSG_NO_PLAYER_ERR "No player found in the map"

# define MSG_TEXTURES_HAVE_DOUBLE_ERR "Textures have a duplicata"
# define MSG_MAP_NOT_SET_ERR "Map is not set"

#endif
