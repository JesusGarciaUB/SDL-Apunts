#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "SmallAsteroid.h"
#include "Bullet.h"
#include "UIText.h"
#include <string>

class GameplayScene : public Scene {
public:
	GameplayScene() : Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	void Exit() override;
private:
	Spaceship* spaceship;
	SDL_Renderer* renderer;
	UIText* lives;
	UIText* score;
	int scoreInt;
};