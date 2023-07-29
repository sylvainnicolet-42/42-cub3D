
#ifndef DEFINE_H
# define DEFINE_H

/** ----- DEFINE ----- **/
# define PROG_NAME "Cub3D"
# define WIN_WIDTH 2000
# define WIN_HEIGHT 1000
# define D_UNIT 0.2
# define D_PLAYER_SCALE 0.2
# define FOV 66
# define D_LINUX 1

/** ----- SUCCESS MESSAGES ----- **/
# define MSG_CLOSE_SUCCESS "Cub3D ended successfully! 🚀"

/** ----- ERROR MESSAGES ----- **/
# define MSG_MALLOC_ERR "Malloc failed!"
# define MSG_ARG_ERR "Wrong Number of arguments"
# define MSG_OPEN_FILE_ERR "File can't be opened!"
# define MSG_FILE_NOT_CUB_ERR "File is not a .cub"
# define MSG_TEXTURES_NOT_SET_ERR "Textures are not set"

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
