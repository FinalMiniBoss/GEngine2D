#include "Drawable.h"

Drawable::Drawable(SDL_Renderer* _renderer) :
	_Renderer(_renderer) {}

Drawable::~Drawable()
{
}

void Drawable::onUpdate(std::chrono::steady_clock::time_point _frameTime)
{
}

void Drawable::draw()
{
	this->onDraw();

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

void Drawable::moveTo(Vector2D<int>&)
{
}
