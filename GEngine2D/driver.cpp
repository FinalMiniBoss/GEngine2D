//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "GEngine2D.h"

//Screen dimension constants

class TestScene :
    public Scene {
    int r = 0xff;
    int g = 0x00;
    int b = 0x00;
    int dr = -1;
    int dg = +0;
    int db = +1;

    inline void drawTest(SDL_Renderer* _renderer) {
        if (r == 0xff)dr = -1;
        if (b == 0xff)dr = +1;
        if (g == 0xff)dg = -1;
        if (r == 0xff)dg = +1;
        if (b == 0xff)db = -1;
        if (g == 0xff)db = +1;

        r += dr;
        g += dg;
        b += db;

        r = std::min(std::max(r, 0x00), 0xff);
        g = std::min(std::max(g, 0x00), 0xff);
        b = std::min(std::max(b, 0x00), 0xff);

        //
        //DEBUG
        //
        (std::cout << "                        \rr: " << r << "\tg: " << g << "\tb: " << b << '\r').flush();

        SDL_SetRenderDrawColor(_renderer, r, g, b, 0xff);
    }

public:
    inline virtual void onDraw() {
        drawTest(_Renderer);
    }
    inline virtual void onUpdate(float _deltaTime)
    {
        for (auto& child : _children)
        {
            if (std::dynamic_pointer_cast<Drawable>(child))
            {
                std::dynamic_pointer_cast<Drawable>(child)->moveBy({ rand() % 3 - 1,rand() % 3 - 1 });
            }
        }
    }
};



int main(int argc, char* args[])
{
    srand(static_cast<unsigned int>(time(NULL)));
    try { GEngine2D::Init("Colors!!"); }
    catch (const std::exception& e)
    {
        std::cout << e.what();

        exit(-1);
    }

    TestScene j;
    for (size_t i = 0; i < 5; i++)
    {
        std::shared_ptr<Drawable> q = 
            std::make_shared<Drawable>(GEngine2D::Renderer());
        q->moveTo({ rand() % 1080,rand() % 1080 });
        q->size({ rand() % 256,rand() % 256 });
        SDL_Surface* s = IMG_Load("circles.png");
        SDL_SetColorKey(s, 1, SDL_MapRGB(s->format, 0xff, 0x00, 0xff));
        SDL_Texture* t = (SDL_CreateTextureFromSurface(GEngine2D::Renderer(), s));
        SDL_FreeSurface(s);
        q->texture(t);

        j.addChild(q);
    }
    j.present();

    while(GEngine2D::Update());    

    GEngine2D::Close();

    return 0;
}