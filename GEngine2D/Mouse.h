#pragma once
#include "Vector2D.h"

#include <SDL.h>
#include <array>

class Mouse
{
	friend class GEngine2D;
public:
	enum Button
	{
		Left = 0,
		Middle  = 1,
		Right = 2
	};
private:
	static int _x;
	static int _y;
	static std::array<bool, 3> _pressed;
	static std::array<bool, 3> _held;
	static std::array<bool, 3> _released;
	static int _scroll;

public:
	static Vector2D<int> Position();
	static std::array<bool,3> Pressed();
	static std::array<bool, 3> Held();
	static std::array<bool, 3> Released();
	static int Scroll();

};

