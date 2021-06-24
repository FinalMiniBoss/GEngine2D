#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#include "Drawable.h"
class Scene : public Drawable
{
private:
	static Scene* _CurrentScene;
public:
	static Scene* CurrentScene();

private:

public:
	Scene();
	~Scene();

	void present();
	virtual void onDraw();
	virtual void onUpdate(std::chrono::steady_clock::time_point);
};

