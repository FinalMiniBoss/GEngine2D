#pragma once
#include <SDL.h>
#include "Vector.h"

#include "Entity.h"

class Drawable : public Entity
{
private:
public:

protected:
	SDL_Renderer* _Renderer = nullptr;
	bool _visible = true;

	Vector2D<int> _position = { 0,0 };
	Vector2D<int> _size = { 1,1 };
	Vector2D<float> _scale = { 1,1 };

	
public:
	Drawable() = delete;
	Drawable(SDL_Renderer*);
	Drawable(Drawable&);
	Drawable& operator=(Drawable&);
	~Drawable();

	void onUpdate(std::chrono::steady_clock::time_point);
	void draw();
	virtual void onDraw();

	void show();
	void hide();
	const bool isVisible();

	void moveTo(Vector2D<int>&);
	void moveBy(Vector2D<int>&);
	const Vector2D<int> position();

	void scaleTo(Vector2D<float>&);
	void scaleBy(Vector2D<float>&);
	const Vector2D<float> scale();

	const Vector2D<int> size();
	void size(Vector2D<int>);

};

