//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>

#include "GEngine2D.h"

//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    try { GEngine2D::Init("Colors!!"); }
    catch (const std::exception& e)
    {
        std::cout << e.what();

        exit(-1);
    }

    Scene j;
    for (size_t i = 0; i < 5; i++)
    {
        j.addChild(std::make_shared<Entity>());
    }
    j.present();

    while(GEngine2D::Update());

    GEngine2D::Close();

    return 0;
}