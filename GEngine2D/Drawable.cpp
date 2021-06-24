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
	SDL_Rect g;
	g.x = _position._x;
	g.y = _position._y;
	g.w = _size._x;
	g.h = _size._y;
	SDL_RenderCopy(_Renderer, _texture, NULL, &g);

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

void Drawable::texture( SDL_Texture* _texture)
{
	this->_texture = _texture;
}
