#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
private:
	void UpdateMovement(float dt) override { GameObject::UpdateMovement(dt); }
	void Update(float dt) override { DestroyOnLeave(); UpdateMovement(dt); }
	void DestroyOnLeave();
	float TimeUntilDeath;
	float frameTime = 1.0f / (float)60;
	float currentTime;
public:
	Bullet(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, float tud);
};