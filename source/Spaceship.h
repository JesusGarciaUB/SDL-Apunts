#pragma once
#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject {
public:
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl);

private:
	
	void UpdateMovement(float dt) override;
};