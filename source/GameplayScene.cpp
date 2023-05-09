#include "GameplayScene.h"

void GameplayScene::Start(SDL_Renderer* rend)
{
	Scene::Start(rend);
	renderer = rend;
	spaceship = new Spaceship(rend, Vector2(100.f, 100.f), 0.0f, Vector2(1.f, 1.f));
	objects.push_back(spaceship);
	for (int i = 0; i < 10; i++) {
		objects.push_back(new Asteroid(rend));
	}
}

void GameplayScene::Update(float dt)
{
	Scene::Update(dt);
	
	if (IM.GetKey(SDLK_SPACE, DOWN)) {
		objects.push_back(new Bullet(renderer, spaceship->GetPosition(), spaceship->GetRotation(), Vector2(1.f, 1.f), 3.f));
	}

	

	for (auto it = objects.begin(); it != objects.end(); it++) {
		if (Asteroid* a = dynamic_cast<Asteroid*>(*it)) {
			Vector2 sToA = a->GetPosition() - spaceship->GetPosition();
			float distanceSquare = sToA.x * sToA.x + sToA.y * sToA.y;
			float radiusSum = 20 + 20;
			radiusSum *= radiusSum;
			if (distanceSquare < radiusSum) {
				spaceship->Destroy();
				a->Destroy();

				finished = true;
				targetScene = "Main Menu";
			}

			for (auto it2 = objects.begin(); it2 != objects.end(); it2++) {
				if (Bullet* b = dynamic_cast<Bullet*>(*it2)) {
					Vector2 sToB = a->GetPosition() - b->GetPosition();
					float distanceSquare2 = sToB.x * sToB.x + sToB.y * sToB.y;
					float radiusSum2 = 20 + 20;
					radiusSum2 *= radiusSum2;
					if (distanceSquare2 < radiusSum2) {
						b->Destroy();
						a->Destroy();
					}
				/*
					if (a->IsPendingDestroy()) {
						
						objects.push_back(new MediumAsteroid(renderer, a->GetPosition(), 4));
						objects.push_back(new MediumAsteroid(renderer, a->GetPosition(), 4));
					}
				
				
					if (a->IsPendingDestroy()) {
						objects.push_back(new SmallAsteroid(renderer, a->GetPosition(), 4));
						objects.push_back(new SmallAsteroid(renderer, a->GetPosition(), 4));
					}
				*/
				}
				
				
			}
		}
	}

}

void GameplayScene::Render(SDL_Renderer* rend)
{
	Scene::Render(rend);
	std::cout << "Gameplay" << std::endl;
}

void GameplayScene::Exit()
{
	for (auto it = objects.begin(); it != objects.end(); it++) delete (*it);
	objects.clear();
}
