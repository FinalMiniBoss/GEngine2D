#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <exception>
#include <chrono>
#include <iostream>
#include <math.h>
#include <algorithm>

#include "Scene.h"

class GEngine2D {
    static SDL_Window* _Window;
    static SDL_Surface* _Surface;
    static SDL_Renderer* _Renderer;

    static long long _deltaTime;
    static std::chrono::steady_clock::time_point _frameTime;
    static uint16_t _frameLimit;

    virtual void _() = 0;

public:
    static void Init(std::string);
    static void Close();

    static bool Update();
    static void Draw();

    static SDL_Window* Window();
    static SDL_Surface* Surface();
    static SDL_Renderer* Renderer();
};