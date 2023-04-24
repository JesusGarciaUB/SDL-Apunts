#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, Vector2 pos, float rot, Vector2 scl) : GameObject(renderer)
{
	position = pos;
	rotation = rot;
	scale = scl;
}

void Spaceship::Update(float dt)
{
	UpdateMovement(dt);
}

void Spaceship::Render(SDL_Renderer* renderer)
{
	SDL_Rect source {0, 0, 31, 39};
	SDL_Rect dest {
		position.x - (int)((float)source.w * scale.x / 2.0f), 
		position.y - (int)((float)source.h * scale.y / 2.0f), 
		(float)source.w * scale.x, 
		(float)source.h * scale.y
	};

	SDL_RenderCopyEx(
		renderer, texture, 
		&source, &dest, 
		90.f + rotation, 
		NULL, //NULL = centered
		SDL_FLIP_NONE);
}

void Spaceship::UpdateMovement(float dt)
{
	if (IM.GetKey(SDLK_RIGHT, HOLD) || IM.GetKey(SDLK_RIGHT, DOWN)) rotation += dt * 360;
	if (IM.GetKey(SDLK_LEFT, HOLD) || IM.GetKey(SDLK_LEFT, DOWN)) rotation -= dt * 360;
	if (IM.GetKey(SDLK_UP, HOLD) || IM.GetKey(SDLK_UP, DOWN)) {
		Vector2 dir;
		float rotationInRadians = rotation * (M_PI / 180.f);
		dir.x = cos(rotationInRadians);
		dir.y = sin(rotationInRadians);
		velocity = velocity + (dir * dt * 100.0f);
	}
	Vector2 velocityDT = velocity * dt;
	position = position + velocityDT;
}
