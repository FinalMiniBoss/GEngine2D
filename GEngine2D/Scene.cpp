#include "Scene.h"

Scene* Scene::_CurrentScene = nullptr;

Scene* Scene::CurrentScene() { return _CurrentScene; }

void Scene::present() {
	_CurrentScene = (this);
}

int r = 0xff;
int g = 0x00;
int b = 0x00;
int dr = -1;
int dg = +0;
int db = +1;

void drawTest(SDL_Renderer* _renderer) {
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

void Scene::draw(SDL_Renderer* _renderer) {
    drawTest(_renderer);
}