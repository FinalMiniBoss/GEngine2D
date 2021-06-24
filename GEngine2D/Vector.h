#pragma once
template<class T>
struct Vector2D
{
//private:
	T _x = 0;
	T _y = 0;
public:
	Vector2D() = default;
	inline Vector2D(T _x, T _y) : _x(_x), _y(_y) {}
	~Vector2D() {}

	inline const Vector2D& operator+(const Vector2D& _rhs) 
	{
		return Vector2D( this->_x + _rhs._x, this->_y + _rhs._y );
	}
	inline Vector2D& operator-()              
	{
		return { -this->_x,-this->_y };
	}
	inline Vector2D& operator-(const Vector2D& _rhs)
	{
		return this + (-_rhs); 
	}

	inline Vector2D& operator*(const Vector2D& _rhs)
	{
		return { this->_x * _rhs._x,this->_y * _rhs._y };
	}
	template<class K>
	inline Vector2D& operator*(const K _rhs)
	{
		return { this->_x * _rhs,this->_y * _rhs };
	}

	inline Vector2D& operator=(const Vector2D& _rhs) 
	{
		this->_x = _rhs._x;
		this->_y = _rhs._y;
		return *this; 
	} 

};
