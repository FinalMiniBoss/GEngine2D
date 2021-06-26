#include "Label.h"
#include "GEngine2D.h"

Label::Label(std::string* _text, std::string _font) :
	Drawable(GEngine2D::Renderer()), _text(_text)
{
	this->_font = TTF_OpenFont(_font.c_str(), 32);
	updateTexture();
}

Label::~Label() {}

std::string* Label::text() const
{
	return _text;
}
void Label::text(std::string& _t)
{
	_text = &_t;
	updateTexture();
}
void Label::font(std::string& _f)
{
	this->_font = TTF_OpenFont(_f.c_str(), 32);
	updateTexture();
}

void Label::updateTexture()
{
	if (!_Renderer)_Renderer = GEngine2D::Renderer();
	if (_texture) delete _texture;
	if (!_font || !_text) return;
	SDL_Surface* _textSurface = TTF_RenderText_Solid(_font, _text->c_str(), { 0xff,0xff,0xff });
	_texture = new Texture(SDL_CreateTextureFromSurface(_Renderer, _textSurface));
	_size = { _textSurface->w,_textSurface->h };
	_texture->setClip({ 0,0,_textSurface->w,_textSurface->h });
	SDL_FreeSurface(_textSurface);
}

void Label::onDraw()
{
	;
}