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
	inline TestSprite() :
		Drawable(GEngine2D::Renderer())
	{
		size({ rand() % (257 - 32) + 32,rand() % (257 - 32) + 32 });
		moveTo({ rand() % 1080 - _size._x + 1,rand() % 1080 - _size._y + 1 });
		std::string k = "circles.png";
		Texture* t = new Texture(k);
		t->setClip({ (Vector2D<int>(rand() % 4,rand() % 2) * 128),Vector2D<int>(128,128) });
		_texture = t;
	}
	inline virtual void onUpdate(float _deltaTime)
	{
		if (++counter == 5) {
			moveBy({ rand() % 11 - 5,rand() % 11 - 5 });
			clamp(_position._x, 0, 1080 - _size._x);
			clamp(_position._y, 0, 1080 - _size._y);
			counter = 0;
		}
	}
};
class TestWalk :
	public Drawable
{
public:
	inline TestWalk() :
		Drawable(GEngine2D::Renderer())
	{
		size({ 64,128 });
		moveTo({ 506,476 });
		std::vector<AnimatedTexture::Frame> frames;
		for (int i = 1; i < 10; i++)
		{
			frames.push_back({ {64 * i,0,64,128},5 });
		}
		_texture = new AnimatedTexture("Walk.png", frames);
	}
	inline void onDraw() {
		;
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
	std::shared_ptr<TestWalk> walker = std::make_shared<TestWalk>();
	j.addChild(walker);
	std::shared_ptr<Label> label = std::make_shared<Label>();
	std::string font = "font.ttf";
	std::string text = "This is a label.";
	label.get()->font(font);
	label.get()->text(text);
	label.get()->moveTo({ 100,100 });
	j.addChild(label);

	std::shared_ptr<Label> label2 = std::make_shared<Label>();
	std::string text2 = "This is another label.";
	label2.get()->font(font);
	label2.get()->text(text2);
	label2.get()->moveTo({ 132,132 });
	j.addChild(label2);

	j.present();

	while (GEngine2D::Update());

	GEngine2D::Close();

	return 0;
}