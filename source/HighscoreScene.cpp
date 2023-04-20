#include "HighscoreScene.h"

void HighscoreScene::Start(SDL_Renderer* rend)
{
	Scene::Start(rend);
}

void HighscoreScene::Update(float dt)
{
	Scene::Update(dt);
	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		finished = true;
		targetScene = "Main Menu";
	}
}

void HighscoreScene::Render(SDL_Renderer* rend)
{
	Scene::Render(rend);
	cout << "Highscore" << endl;
}

void HighscoreScene::Exit()
{
	
}
