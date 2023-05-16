#include "MenuScene.h"

void MenuScene::Start(SDL_Renderer* rend)
{
	Scene::Start(rend);
	
	uiObjects.push_back(new UIText(
		rend,
		Vector2(GAME_WIDTH/2, GAME_HEIGHT/4), 0.f, Vector2(1, 1),
		"ASTEROIDS",
		"resources/Hyperspace.ttf"
	));
	
	uiObjects.push_back(new UIText(
		rend,
		Vector2(120, (GAME_HEIGHT / 4 + GAME_HEIGHT / 2)), 0.f, Vector2(1, 1),
		"Jesus Garcia",
		"resources/Hyperspace.ttf"
	));

	uiObjects.push_back(new UIText(
		rend,
		Vector2(155, (GAME_HEIGHT / 4 + GAME_HEIGHT / 2) + 25), 0.f, Vector2(1, 1),
		"Miquel Hernandez",
		"resources/Hyperspace.ttf"
	));

	uiObjects.push_back(new UIButton(
		rend, Vector2(GAME_HEIGHT / 2, GAME_WIDTH / 2), 0.f, Vector2(1, 1),
		new UIText(
			rend, Vector2(GAME_HEIGHT / 2, GAME_WIDTH / 2), 0.f, Vector2(1, 1),
			"Gameplay",
			"resources/Hyperspace.ttf"
		),
		160, 30
	));
}

void MenuScene::Update(float dt)
{
	Scene::Update(dt);
	
	if (IM.GetLeftClick() && CheckPointInsideCenteredRectangle(Vector2(IM.GetMouseX(), IM.GetMouseY()), uiObjects[3]->GetPos(), uiObjects[3]->GetWidth(), uiObjects[3]->GetHeight())) {
		finished = true;
		targetScene = "Gameplay";
	}
}

