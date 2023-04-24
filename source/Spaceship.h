#pragma once
#include "GameObject.h"
#include "InputManager.h"

class Spaceship : public GameObject {
public:
	Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl);

	void Update(float dt) override;
	void Render(SDL_Renderer* renderer) override;
private:
	
	void UpdateMovement(float dt);

	//Velocity
	Vector2 velocity;
	float angularVelocity;
	//Drag
	float linearDrag;
	float angularDrag;
	//Acceleration
	float accelerationFactor;
	float angularAccelerationFactor;
};