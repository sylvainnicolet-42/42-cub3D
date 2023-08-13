/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:50:26 by mjulliat          #+#    #+#             */
/*   Updated: 2023/08/13 13:52:24 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

enum e_xcode_event
{
	E_KEY_PRESS = 2,
	E_KEY_UP = 3,
	E_ON_MOUSEDOWN = 4,
	E_ON_MOUSEUP = 5,
	E_ON_MOUSEMOVE = 6,
	E_ON_DESTROY = 17,
};

enum e_xcode_mask
{
	E_KEY_PRESS_MASK = 2,
};

enum e_key_linux
{
	E_KEY_LINUX_A = 97,
	E_KEY_LINUX_S = 115,
	E_KEY_LINUX_D = 100,
	E_KEY_LINUX_W = 119,
	E_KEY_LINUX_E = 101,
	E_KEY_LINUX_R = 114,
	E_KEY_LINUX_1 = 49,
	E_KEY_LINUX_2 = 50,
	E_KEY_LINUX_3 = 51,
	E_KEY_LINUX_ESC = 65307,
	E_KEY_LINUX_ARROW_LEFT = 65361,
	E_KEY_LINUX_ARROW_RIGHT = 65363,
	E_KEY_LINUX_ARROW_DOWN = 65364,
	E_KEY_LINUX_ARROW_UP = 65362,
};

enum e_key
{
	E_KEY_A = 0,
	E_KEY_S = 1,
	E_KEY_D = 2,
	E_KEY_W = 13,
	E_KEY_E = 14,
	E_KEY_R = 15,
	E_KEY_1 = 18,
	E_KEY_2 = 19,
	E_KEY_3 = 20,
	E_KEY_ESC = 53,
	E_KEY_ARROW_LEFT = 123,
	E_KEY_ARROW_RIGHT = 124,
	E_KEY_ARROW_DOWN = 125,
	E_KEY_ARROW_UP = 126,
};

enum e_mouse
{
	E_MOUSE_LEFT = 1,
	E_MOUSE_RIGHT = 2,
	E_MOUSE_MIDDLE = 3,
	E_MOUSE_SCROLL_UP = 4,
	E_MOUSE_SCROLL_DOWN = 5,
};

enum e_direction
{
	E_SOUTH = 1,
	E_NORTH = 2,
	E_EAST = 3,
	E_WEST = 4,
};

enum e_wall
{
	E_WALL = 1,
	E_RGB = 2,
	E_PLAYER = 3,
	E_ALLEY = 4,
	E_DOOR = 5,
};

enum e_moves
{
	E_FORWARD = 1,
	E_LEFT = 2,
	E_RIGHT = 3,
	E_BACKWARD = 4,
};

#endif
