#pragma once
#include "Drawable.h"
#include <SDL_ttf.h>
#include <string>
class Label :
    public Drawable
{
protected:
    std::string _text = "";
    TTF_Font* _font = nullptr;
public:
    Label() = delete;
    Label(std::string);
    ~Label();
};

