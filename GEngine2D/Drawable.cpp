#include "Drawable.h"

Drawable::Drawable(SDL_Renderer* _renderer) :
	_Renderer(_renderer) {}

Drawable::Drawable(Drawable&)
{
}

Drawable::~Drawable()
{
}

void Drawable::onUpdate(float _deltaTime)
{
}

void Drawable::draw()
{
	this->onDraw();
	SDL_Rect _r;
	_r.x = _position._x;
	_r.y = _position._y;
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
