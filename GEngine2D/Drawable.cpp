#include "Drawable.h"
#include "Mouse.h"

Drawable::Drawable(SDL_Renderer* _renderer) :
	_Renderer(_renderer) {}

Drawable::Drawable(Drawable&)
{
}

Drawable::~Drawable()
{
}

void Drawable::setAnchor(Vector2D<float> _a)
{
	_anchorPoint = _a;
}

void Drawable::onUpdate(float _deltaTime)
{
}

void Drawable::draw()
{
	this->onDraw();
	SDL_Rect _r;
	Vector2D<int> offset = { static_cast<int>(_size._x * _anchorPoint._x),
							static_cast<int>(_size._y * _anchorPoint._y )};
	_r.x = _position._x - offset._x;
	_r.y = _position._y - offset._y;
	_r.w = _size._x;
	_r.h = _size._y;
	
	if (_texture) {
		_texture->onDraw();
		SDL_RenderCopy(_Renderer, _texture->operator()(), _texture->clip(), &_r);
	}

	for (std::shared_ptr<Entity> child : _children)
	{
		if (std::dynamic_pointer_cast<Drawable>(child))
			std::dynamic_pointer_cast<Drawable>(child)->draw();
	}
}

void Drawable::onDraw()
{
}



void Drawable::onClick(int)
{
}



void Drawable::onHold(int)
{
}



void Drawable::onRelease(int)
{
}



void Drawable::onScroll(int)
{
}

void Drawable::show()
{
	_visible = true;
}

void Drawable::hide()
{
	_visible = false;
}

const bool Drawable::isVisible()
{
	return _visible;
}

void Drawable::moveTo(const Vector2D<int>& _move)
{
	_position = _move;
}

void Drawable::moveBy(const Vector2D<int>& _move)
{
	_position = _position + _move;
}

const Vector2D<int> Drawable::size()
{
	return _size;
}

void Drawable::size(Vector2D<int> _size)
{
	this->_size = _size;
}

void Drawable::texture( Texture* _texture)
{
	this->_texture = _texture;
}
