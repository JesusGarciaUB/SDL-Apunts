#pragma once

#include "GameObject.h"
#include "InputManager.h"

class Enemy : public GameObject {

private:
	bool canShoot;

	float maxShotTime;
	float lastShotTime;

	float changeDirectionTime;

	void UpdateMovement(float dt) override;
	void UpdateShot(float dt);

protected:
	void Update(float dt) override;

	int score;

public:
	Enemy(SDL_Renderer* rend);

	bool BulletShooted();

	int GetScore() { return score; }
};