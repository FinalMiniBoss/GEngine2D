#include "Mouse.h"

int Mouse::_x = 0;
int Mouse::_y = 0;
std::array<bool, 3> Mouse::_pressed = {};
std::array<bool, 3> Mouse::_held = {};
std::array<bool, 3> Mouse::_released = {};
int Mouse::_scroll = 0;



Vector2D<int> Mouse::Position()
{
	return { _x,_y };
}

std::array<bool, 3> Mouse::Pressed()
{
	return _pressed;
}

std::array<bool, 3> Mouse::Held()
{
	return _held;
}

std::array<bool, 3> Mouse::Released()
{
	return _released;
}

int Mouse::Scroll()
{
	return 0;
}
