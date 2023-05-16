#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) : GameObject(renderer, 31, 39, Vector2(0, 0))
{
	position = pos;
	rotation = rot;
	scale = scl;

	velocity = Vector2();
	angularVelocity = 0.0f;

	acceleration = Vector2();
	angularAcceleration = 0.0f;

	linearDrag = 1.2f;
	angularDrag = 6.f;

	accelerationFactor = 500.f;
	angularAccelerationFactor = 100000.f;
}

void Spaceship::UpdateMovement(float dt)
{
	angularAcceleration = 0;
	acceleration = Vector2();

	if (IM.GetKey(SDLK_RIGHT, HOLD) || IM.GetKey(SDLK_RIGHT, DOWN)) angularAcceleration = dt * angularAccelerationFactor;
	if (IM.GetKey(SDLK_LEFT, HOLD) || IM.GetKey(SDLK_LEFT, DOWN)) angularAcceleration = dt * -angularAccelerationFactor;
	if (IM.GetKey(SDLK_UP, HOLD) || IM.GetKey(SDLK_UP, DOWN)) {
		Vector2 dir;
		float rotationInRadians = rotation * (M_PI / 180.f);
		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);
		acceleration = dir * accelerationFactor;
	}

	GameObject::UpdateMovement(dt);
}
