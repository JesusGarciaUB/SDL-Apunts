#pragma once
#include "Scene.h"
#include <SDL.h>

using namespace std;

class HighscoreScene : public Scene {
public:
	HighscoreScene() : Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;
private:

};