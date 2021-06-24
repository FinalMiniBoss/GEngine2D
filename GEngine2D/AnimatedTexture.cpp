#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture(std::string _path, std::vector<Frame> _frames) :
	Texture(_path), _frames(_frames) {}

void AnimatedTexture::onDraw()
{
	if (_frameCounter>_frames[_currentFrame].frames)
	{
		_frameCounter = 0;
		_currentFrame++;
		if (_currentFrame >= _frames.size()) 
		{
			_currentFrame = 0;
		}
	}
	_clip.x = _frames[_currentFrame].clip.origin._x;
	_clip.y = _frames[_currentFrame].clip.origin._y;
	_clip.w = _frames[_currentFrame].clip.size._x;
	_clip.h = _frames[_currentFrame].clip.size._y;
	_frameCounter++;
}