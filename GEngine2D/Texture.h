#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Rect.h"

class Texture
{
protected:
	SDL_Texture* _texture = nullptr;
	SDL_Rect _clip;
public:
	Texture() = default;
	Texture(std::string);
	~Texture();

	bool setClip(Rect<int>);
	const SDL_Rect* clip() const;
	SDL_Texture* operator()(void) const;
	virtual void onDraw();
};

