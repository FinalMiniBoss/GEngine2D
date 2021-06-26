#pragma once
#include "Vector2D.h"

#include "Entity.h"
#include "Texture.h"
#include "AnimatedTexture.h"

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

	Texture* _texture = nullptr;

	
public:
	Drawable() = default;
	Drawable(SDL_Renderer*);
	Drawable(Drawable&);
	Drawable& operator=(Drawable&);
	~Drawable();

	void onUpdate(float);
	void draw();
	virtual void onDraw();

	void show();
	void hide();
	const bool isVisible();

	void moveTo(const Vector2D<int>&);
	void moveBy(const Vector2D<int>&);
	const Vector2D<int> position();

	void scaleTo(Vector2D<float>&);
	void scaleBy(Vector2D<float>&);
	const Vector2D<float> scale();

	const Vector2D<int> size();
	void size(Vector2D<int>);

	void texture(Texture*);

};

