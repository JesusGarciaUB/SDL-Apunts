#pragma once
#include "GameObject.h"

class Bullet : public GameObject {
private:
	void UpdateMovement(float dt) override { GameObject::UpdateMovement(dt); }
	void Update(float dt) override { DestroyOnLeave(); UpdateMovement(dt); }
	void DestroyOnLeave();
	float TimeUntilDeath;
public:
	Bullet(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, float tud);
};