
#ifndef ENUM_H
# define ENUM_H

enum e_xcode_event
{
	E_KEY_PRESS = 2,
	E_KEY_UP = 3,
	E_ON_DESTROY = 17,
};

enum e_xcode_mask
{
	E_KEY_PRESS_MASK = 2,
};

enum e_key
{
	E_KEY_A = 0,
	E_KEY_S = 1,
	E_KEY_D = 2,
	E_KEY_W = 13,
	E_KEY_1 = 18,
	E_KEY_2 = 19,
	E_KEY_3 = 20,
	E_KEY_ESC = 53,
	E_KEY_ARROW_LEFT = 123,
	E_KEY_ARROW_RIGHT = 124,
	E_KEY_ARROW_DOWN = 125,
	E_KEY_ARROW_UP = 126,
};

enum e_wall
{
	E_WALL = 1,
	E_RGB = 2,
	E_PLAYER = 3,
	E_ALLEY = 4,
};

enum e_moves
{
	E_FORWARD = 1,
	E_LEFT = 2,
	E_RIGHT = 3,
	E_BACKWARD = 4,
};

#endif
