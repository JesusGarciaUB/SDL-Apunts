#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend)
{
	Scene::Start(rend);
	uiObjects.push_back(new UIImage(
		rend,
		Vector2(250, 250), 0.f, Vector2(0.2f, 0.2f),
		"resources/obama.png",
		2500, 2500, Vector2(0, 0)));
	uiObjects.push_back(new UIText(
		rend,
		Vector2(250, 250), 0.f, Vector2(1, 1),
		"Hola bona tarda",
		"resources/Hyperspace.ttf"
	));
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
	std::cout << "Main Menu" << std::endl;
}

void MenuScene::Exit()
{
	
}
