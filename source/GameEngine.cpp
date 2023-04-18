#include "GameEngine.h"
#include "GameObject.h"

GameEngine::GameEngine(int windowWidth, int windowHeight)
{
	InitSDL();
	InitWindowAndRenderer(windowWidth, windowHeight);
}

void GameEngine::Update()
{
	GameObject object(renderer);
	bool playing = true;
	while (playing) {
		//Input
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) playing = false;
		}

		//Logic
		object.Update(0.f);

		//Render
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		object.Render(renderer);

		//Objects
		//SDL_RenderCopyEx()
		SDL_RenderPresent(renderer);
	}
}

void GameEngine::Finish()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void GameEngine::InitSDL()
{
	int result = SDL_Init(SDL_INIT_VIDEO);
	if (result < 0) cout << "SDL_Init error: " << SDL_GetError();
}

void GameEngine::InitWindowAndRenderer(int windowWidth, int windowHeight)
{
	window = SDL_CreateWindow("Cosa", 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_SHOWN);
	if (!window) cout << "Error creating window: " << SDL_GetError();

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) cout << "Error creating renderer: " << SDL_GetError();
}
