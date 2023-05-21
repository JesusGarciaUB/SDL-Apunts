#pragma once

#include "GameObject.h"

class EnemyBullet : public GameObject {

protected:
	float lifeTime;

	void Update(float dt) override;
	void UpdateLifetime(float dt);

public:
	EnemyBullet(SDL_Renderer* renderer, Vector2 pos, float velocityFactor);
	void Render(SDL_Renderer* renderer) override;
};