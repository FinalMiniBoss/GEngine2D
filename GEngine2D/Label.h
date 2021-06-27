#pragma once
#include "Drawable.h"
#include <SDL_ttf.h>
#include <string>
class Label :
    public Drawable
{
protected:
    std::string* _text = nullptr;
    TTF_Font* _font = nullptr;
    void updateTexture();
public:
    Label() = default;
    Label(std::string*, std::string = "font.ttf");
    ~Label();

    void text(std::string&);
    std::string* text() const;

    void font(std::string&);
    void onDraw();
};

