#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend)
{
	Scene::Start(rend);
}

void MenuScene::Update(float dt)
{
	Scene::Update(dt);
	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		finished = true;
		targetScene = "Gameplay";
	}

	
	if (IM.GetKey(SDLK_h, DOWN)) {
		finished = true;
		targetScene = "Highscores";
	}
}

void MenuScene::Render(SDL_Renderer* rend)
{
	Scene::Render(rend);
	cout << "Main Menu" << endl;
}

void MenuScene::Exit()
{
	
}
