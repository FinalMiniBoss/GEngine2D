//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>
#include <math.h>

#include "GEngine2D.h"

//Screen dimension constants

template<class K>
void clamp(K& _k, K _min, K _max)
{
	_k = fmin(_max, fmax(_min, _k));
}

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
	}
};
class TestSprite :
	public Drawable
{
	int counter = rand() % 5;
public:
	inline TestSprite():
		Drawable(GEngine2D::Renderer())
	{
		size({ rand() % (257 - 32) + 32,rand() % (257 - 32) + 32 });
		moveTo({ rand() % 1080-_size._x+1,rand() % 1080-_size._y+1 });
		std::string k = "circles.png";
		Texture* t = new Texture(k);
		t->setClip({ (Vector2D<int>(rand() % 4,rand() % 2) * 128),Vector2D<int>(128,128) });
		_texture = t;
	}
	inline virtual void onUpdate(float _deltaTime)
	{
		if (++counter == 5) {
			moveBy({ rand() % 3 - 1,rand() % 3 - 1 });
			clamp(_position._x, 0, 1080 - _size._x);
			clamp(_position._y, 0, 1080 - _size._y);
			counter = 0;
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
	for (size_t i = 0; i < 10; i++)
	{
		std::shared_ptr<TestSprite> q = 
			std::make_shared<TestSprite>();
		

		j.addChild(q);
	}
	j.present();
	std::vector<AnimatedTexture::Frame> frames;
	frames.push_back({ {000,000,128,128},30 });
	frames.push_back({ {128,000,128,128},30 });
	frames.push_back({ {256,000,128,128},30 });
	frames.push_back({ {384,000,128,128},30 });
	frames.push_back({ {000,128,128,128},30 });
	frames.push_back({ {128,128,128,128},30 });
	frames.push_back({ {256,128,128,128},30 });
	frames.push_back({ {384,128,128,128},30 });
	std::dynamic_pointer_cast<TestSprite>(j.children()[j.children().size() - 1]).get()->texture(new AnimatedTexture("circles.png", frames));
	while(GEngine2D::Update());   

	GEngine2D::Close();

	return 0;
}