#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend)
{
	currentState = GameplayState::ALIVE;
	currentStateTime = 0.0f;
	spaceshipHealth = 3;

	Scene::Start(rend);
	renderer = rend;
	RespawnSpaceship();
	currentStateTime = 3.0f;
	scoreInt = 0;

	
	for (int i = 0; i < 10; i++) {
		objects.push_back(new BigAsteroid(rend));
	}

	//--------UI
	uiObjects.push_back(new UIText(
		rend, Vector2(80, 14), 0.f, Vector2(1, 1), "Score: ", "resources/Hyperspace.ttf"
	));

	score = new UIText(
		rend, Vector2(160, 14), 0.f, Vector2(1, 1), "0", "resources/Hyperspace.ttf"
	);
	uiObjects.push_back(score);

	uiObjects.push_back(new UIText(
		rend, Vector2(GAME_WIDTH - 80, 14), 0.f, Vector2(1, 1), "Lives: ", "resources/Hyperspace.ttf"
	));

	lives = new UIText(
		rend, Vector2(GAME_WIDTH - 30, 14), 0.f, Vector2(1, 1), std::to_string(spaceshipHealth), "resources/Hyperspace.ttf"
	);
	uiObjects.push_back(lives);
}

void GameplayScene::Update(float dt)
{
	currentStateTime += dt;
	int asteroidsLeft = 0;
	int objectsSize = objects.size();
	for (int i = 0; i < objectsSize; i++){
		if (BigAsteroid* big = dynamic_cast<BigAsteroid*>(objects[i])) {
			asteroidsLeft++;
			if (big->IsPendingDestroy()) {
				scoreInt += 50;
				score->ChangeText(std::to_string(scoreInt));
				objects.push_back(new MediumAsteroid(renderer, big->GetPosition()));
				objects.push_back(new MediumAsteroid(renderer, big->GetPosition()));
			}
		}
	}

	for (int i = 0; i < objectsSize; i++) {
		if (MediumAsteroid* medium = dynamic_cast<MediumAsteroid*>(objects[i])) {
			asteroidsLeft++;
			if (medium->IsPendingDestroy()) {
				scoreInt += 30;
				score->ChangeText(std::to_string(scoreInt));
				objects.push_back(new SmallAsteroid(renderer, medium->GetPosition()));
				objects.push_back(new SmallAsteroid(renderer, medium->GetPosition()));
			}
		}
	}

	for (int i = 0; i < objectsSize; i++) {
		if (SmallAsteroid* small = dynamic_cast<SmallAsteroid*>(objects[i])) {
			asteroidsLeft++;
			if (small->IsPendingDestroy()) {
				scoreInt += 20;
				score->ChangeText(std::to_string(scoreInt));
			}
		}
	}

	Scene::Update(dt);
	
	if (spaceship != nullptr) {
		if (IM.GetKey(SDLK_SPACE, DOWN)) {
			Vector2 offset = Vector2(cos(spaceship->GetRotation() * M_PI / 180), sin(spaceship->GetRotation() * M_PI / 180)) * spaceship->GetRadius();
			objects.push_back(new Bullet(renderer, spaceship->GetPosition() + offset, spaceship->GetRotation(), Vector2(1.f, 1.f), 1.2f, 500.f));
		}
	}

	if (asteroidsLeft == 0) {
		for (int i = 0; i < 10; i++) {
			objects.push_back(new BigAsteroid(renderer));
		}
	}

	spawnEnemy += dt;
	if (spawnEnemy >= 15.0f && canEnemySpawn) {
		RespawnEnemy();
		canEnemySpawn = false;
	}

	if (enemy != nullptr) {
		if (enemy->BulletShooted())
			objects.push_back(new EnemyBullet(renderer, enemy->GetPosition(), 550.0f));
	}

	for (auto it = objects.begin(); it != objects.end(); it++) {
		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
			if (spaceship != nullptr && currentStateTime > stateTimeThreshold) {
				if (CheckColision(a->GetPosition(), a->GetRadius(), spaceship->GetPosition(), spaceship->GetRadius())) {
					DestroySpaceship();
				}
			}

			for (auto it2 = objects.begin(); it2 != objects.end() && !a->IsPendingDestroy(); it2++) {
				if (Bullet* b = dynamic_cast<Bullet*>(*it2)) {
					if (CheckColision(a->GetPosition(), a->GetRadius(), b->GetPosition(), b->GetRadius())) {
						b->Destroy();
						a->Destroy();
					}
				}	
			}
		}
		if (Enemy* e = dynamic_cast<Enemy*>(*it)) {
			if (spaceship != nullptr && currentStateTime > stateTimeThreshold) {
				if (CheckColision(e->GetPosition(), e->GetRadius(), spaceship->GetPosition(), spaceship->GetRadius())) {
					DestroyEnemy();
					DestroySpaceship();
					scoreInt += 150;
					score->ChangeText(std::to_string(scoreInt));
				}
			}
			for (auto it2 = objects.begin(); it2 != objects.end() && !e->IsPendingDestroy(); it2++) {
				if (Bullet* b = dynamic_cast<Bullet*>(*it2)) {
					if (CheckColision(e->GetPosition(),	e->GetRadius(), b->GetPosition(), b->GetRadius())) {
						b->Destroy();
						e->Destroy();
					}
				}
			}
		}
		if (EnemyBullet* eb = dynamic_cast<EnemyBullet*>(*it)) {
			if (spaceship != nullptr && currentStateTime > stateTimeThreshold) {
				if (CheckColision(eb->GetPosition(), eb->GetRadius(), spaceship->GetPosition(), spaceship->GetRadius())) {
					eb->Destroy();
					DestroySpaceship();
				}
			}
		}
	}

	if (currentState == GameplayState::DEAD && currentStateTime > stateTimeThreshold) {
		if (spaceshipHealth != 0) RespawnSpaceship();
		else {
			finished = true;
			targetScene = "Main Menu";
		}
	}

}

void GameplayScene::RespawnSpaceship()
{
	spaceship = new Spaceship(renderer, Vector2(GAME_WIDTH / 2, GAME_HEIGHT / 2), 0.0f, Vector2(1.f, 1.f));
	objects.push_back(spaceship);
	currentState = ALIVE;
	currentStateTime = 0.f;
}

void GameplayScene::DestroySpaceship()
{
	spaceship->Destroy();
	spaceship = nullptr;
	currentState = DEAD;
	currentStateTime = 0.f;
	spaceshipHealth--;
	lives->ChangeText(std::to_string(spaceshipHealth));
}

void GameplayScene::RespawnEnemy() {


	enemy = new Enemy(renderer);
	objects.push_back(enemy);
}

void GameplayScene::DestroyEnemy() {

	enemy->Destroy();
	enemy = nullptr;

	canEnemySpawn = true;
	spawnEnemy = 0.0f;
}