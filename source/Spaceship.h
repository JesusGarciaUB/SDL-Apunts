#pragma once
#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject {
public:
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl);
	void SetPosition(Vector2 pos) { position = pos; }
	int hp;
private:
	void UpdateMovement(float dt) override;
};