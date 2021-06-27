#include "GEngine2D.h"

SDL_Window* GEngine2D::_Window = NULL;
SDL_Surface* GEngine2D::_Surface = NULL;
SDL_Renderer* GEngine2D::_Renderer = NULL;

long long GEngine2D::_deltaTime = 0;
std::chrono::steady_clock::time_point GEngine2D::_frameTime = std::chrono::steady_clock::now();
uint16_t GEngine2D::_frameLimit = 60;

void GEngine2D::Init(std::string _title) {

	//Start SDL
	//throw error if fail

	if (SDL_Init(SDL_INIT_VIDEO) < 0) throw std::exception(SDL_GetError());

	//Create Window
	// char* title, posX, posY, sizeX, sizeY, SDL_Flags
	//throw error if fail

	_Window = SDL_CreateWindow(_title.c_str(),
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1920, 1080, SDL_WINDOW_FULLSCREEN);
	if(_Window==NULL) throw std::exception(SDL_GetError());

	//Get window surface (might be useful)

	_Surface = SDL_GetWindowSurface(_Window);

	//create renderer
	//throw error if fail

	_Renderer = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_Renderer == NULL) throw std::exception(SDL_GetError());

	//set window icon
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) throw std::exception(IMG_GetError());

	if (TTF_Init() == -1) throw std::exception(TTF_GetError());

	SDL_SetWindowIcon(_Window, IMG_Load("circles.png"));
	return;

}

void GEngine2D::Close() {
	SDL_DestroyRenderer(_Renderer);
	SDL_DestroyWindow(_Window);
	SDL_Quit();
	return;
}

bool GEngine2D::Update()
{
	Mouse::_scroll = 0;
	SDL_GetMouseState(&Mouse::_x, &Mouse::_y);
	for (size_t i = 0; i < 3; i++)
	{
		if (Mouse::_pressed[i])
		{
			Mouse::_held[i] = true;
		}
		Mouse::_pressed[i] = false;
		Mouse::_released[i] = false;
	}
	SDL_Event e; 
	while (SDL_PollEvent(&e))
	{

		switch (e.type)
		{
		case SDL_KEYUP:
			if (e.key.keysym.sym == SDLK_ESCAPE) return false;
			break;

		//
		//Mouse Stuff
		//

		case SDL_MOUSEBUTTONDOWN:
			Mouse::_pressed[e.button.button - 1] = true;
			break;

		case SDL_MOUSEBUTTONUP:
			Mouse::_released[e.button.button - 1] = true;
			break;

		default:
			break;
		}

		if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				return false;
			}
		}
	}
	//
	//DEBUG: print current FPS
	//
	//(std::cout << "FPS: " << round(1. / ((double)_deltaTime / 1000000000.)) << '\r').flush();

	//
	// Mouse Stuff
	//
	for (size_t i = 0; i < 3; i++)
	{
		if (Mouse::_released[i])
		{
			Mouse::_held[i] = false;
		}
	}

	//get elapsed time between frames and limit to (_frameLimit) FPS

	auto now = std::chrono::steady_clock::now();
	_deltaTime = (now - _frameTime).count();
	/*while (_deltaTime<1000000000/_frameLimit) {
		auto now = std::chrono::steady_clock::now();
		_deltaTime = (now - _frameTime).count();
	}*/
	_frameTime = now;

	

	Scene::CurrentScene()->update(static_cast<float>(_deltaTime)/1000000000.0f);


	//
	// TODO: other stuff
	//








	//Draw the window

	Draw();

	return true;
}

void GEngine2D::Draw() {
	
	if (Scene::CurrentScene() != nullptr)
	{
		SDL_RenderClear(_Renderer);

		Scene::CurrentScene()->draw();

		SDL_RenderPresent(_Renderer);
	}
}

SDL_Window* GEngine2D::Window()
{
	return _Window;
}

SDL_Surface* GEngine2D::Surface()
{
	return _Surface;
}

SDL_Renderer* GEngine2D::Renderer()
{
	return _Renderer;
}

