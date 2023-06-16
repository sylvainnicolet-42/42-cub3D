
#ifndef DEFINE_H
# define DEFINE_H

# define PROG_NAME "Cub3D"
# define WIN_WIDTH 800
# define WIN_HEIGHT 800

// Messages
# define MSG_MALLOC_ERR "Malloc failed!"
# define MSG_CLOSE_SUCCESS "Cub3D ended successfully! 🚀"

enum e_xcode_event
{
	E_KEY_PRESS = 2,
	E_ON_DESTROY = 17
};

enum e_xcode_mask
{
	E_KEY_PRESS_MASK = 2,
};

enum e_key
{
	E_KEY_ESC = 53,
	E_KEY_ARROW_LEFT = 123,
	E_KEY_ARROW_RIGHT = 124,
	E_KEY_ARROW_DOWN = 125,
	E_KEY_ARROW_UP = 126,
};

#endif
