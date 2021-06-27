#include "Texture.h"
#include "GEngine2D.h"
Texture::Texture(std::string _path) 
{
	SDL_Surface* _s = IMG_Load(_path.c_str());
	_texture = SDL_CreateTextureFromSurface(GEngine2D::Renderer(), _s);
	SDL_FreeSurface(_s);
}
Texture::Texture(SDL_Texture* _t) :
	_texture(_t){}

Texture::~Texture() {}

bool Texture::setClip(Rect<int> _clip)
{
	this->_clip.x = _clip.origin._x;
	this->_clip.y = _clip.origin._y;
	this->_clip.w = _clip.size._x;
	this->_clip.h = _clip.size._y;
	return true;
}
const SDL_Rect* Texture::clip() const
{
	return &_clip;
}

SDL_Texture* Texture::operator()(void) const
{
	return _texture;
}

void Texture::onDraw() {}