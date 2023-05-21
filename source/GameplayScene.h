#pragma once
#include "Scene.h"
#include "Spaceship.h"
#include "BigAsteroid.h"
#include "MediumAsteroid.h"
#include "SmallAsteroid.h"
#include "Bullet.h"
#include "UIText.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include <string>

enum GameplayState {ALIVE, DEAD};

class GameplayScene : public Scene {
public:
	GameplayScene() : Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
private:
	Spaceship* spaceship;
	SDL_Renderer* renderer;
	UIText* lives;
	UIText* score;
	int scoreInt;
	GameplayState currentState;
	float currentStateTime;
	const float stateTimeThreshold = 3.0f;
	int spaceshipHealth;
	void RespawnSpaceship();
	void DestroySpaceship();

	Enemy* enemy;
	void DestroyEnemy();
	void RespawnEnemy();
	float spawnEnemy;
	bool canEnemySpawn = true;
};