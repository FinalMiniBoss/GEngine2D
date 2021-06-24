#pragma once
template<class T>
class Vector2D
{
private:
	T _x = 0;
	T _y = 0;
public:
	Vector2D() = default;
	Vector2D(T _x, T _y);
	~Vector2D();

	Vector2D& operator+(Vector2D&);

};

template<class T>
Vector2D<T>::Vector2D(T _x, T _y):
	_x(_x), _y(_y){}

template<class T>
Vector2D<T>::~Vector2D()
{
}

template<class T>
Vector2D<T>& Vector2D<T>::operator+(Vector2D& _rhs)
{
	return { this->_x + _rhs._x, this->_y + _rhs._y };
}
