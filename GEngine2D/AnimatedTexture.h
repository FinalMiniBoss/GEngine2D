#pragma once
#include "Texture.h"
#include "Rect.h"
#include <vector>
class AnimatedTexture :
    public Texture
{
public:
	struct Frame
	{
		Rect<int> clip;
		uint16_t frames;
		inline Frame(Rect<int> _r = { 0,0,0,0 }, uint32_t _f = 1) :
			clip(_r),frames(_f){}
	};
protected:
	uint32_t _frameCounter = 0;
	std::vector<Frame> _frames;
	uint32_t _currentFrame = 0;

public:
	AnimatedTexture() = default;
	AnimatedTexture(std::string, std::vector<Frame>);
	void onDraw();
};

