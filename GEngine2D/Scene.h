#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#include "Entity.h"


class Scene : public Entity
{
	static Scene* _CurrentScene;
public:
	static Scene* CurrentScene();

private:

public:
	Scene() = default;
	~Scene() = default;

	void present();
	void draw(SDL_Renderer* _renderer);
};

