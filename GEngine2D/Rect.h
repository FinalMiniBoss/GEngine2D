#pragma once

#include "Vector2D.h"

template<class T>
struct Rect {
	Vector2D<T> origin = { 0,0 };
	Vector2D<T> size = { 0,0 };

	Rect() = default;
	inline Rect(Vector2D<T> _origin, Vector2D<T> _size) :
		origin(_origin), size(_size) {}
	inline Rect(T _x, T _y, T _w, T _h):
		origin({ _x,_y }), size({ _w,_h }) {}
	inline ~Rect() {}

};