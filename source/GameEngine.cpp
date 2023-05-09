#include "GameEngine.h"

GameEngine::GameEngine(int windowWidth, int windowHeight)
{
	InitSDL();
	InitWindowAndRenderer(windowWidth, windowHeight);
}

void GameEngine::Update()
{
	//GameObject object(renderer);

	//Time control variables
	float dt = 0.f;
	float lastTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
	const float FPS = 60;
	const float frameTime = 1.0f / (float)FPS;

	//Scenes
	unordered_map<string, Scene*> gameScenes;

	gameScenes["Main Menu"] = new MenuScene();
	gameScenes["Gameplay"] = new GameplayScene();
	gameScenes["Highscores"] = new HighscoreScene();

	Scene* currentScene = gameScenes["Gameplay"];
	currentScene->Start(renderer);

	while (!IM.GetQuit()) {

		//dt time control
		float currentTime = (double)SDL_GetPerformanceCounter() / (double)SDL_GetPerformanceFrequency();
		dt += currentTime - lastTime;
		lastTime = currentTime;

		if (dt > frameTime) {
			//Input
			IM.Listen();

			//Logic
			//object.Update(0.f);
			currentScene->Update(dt);

			//Render
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			currentScene->Render(renderer);
			//object.Render(renderer);

			//Objects
			SDL_RenderPresent(renderer);

			//Scene transition
			if (currentScene->IsFinished()) { 
				currentScene->Exit(); 
				currentScene = gameScenes[currentScene->GetTargetScene()];
				currentScene->Start(renderer);
			}

			dt -= frameTime;
		}
	}
	currentScene->Exit();
	for (auto it = gameScenes.begin(); it != gameScenes.end(); it++) {
		delete it->second;
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
	if (TTF_Init() == -1) std::cout << "TTF_Init error: " << TTF_GetError();
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
