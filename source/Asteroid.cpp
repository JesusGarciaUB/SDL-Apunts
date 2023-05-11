#include "Asteroid.h"

Asteroid::Asteroid(SDL_Renderer* rend) : GameObject(rend, 40, 40, Vector2(40, 2))
{
	float objectRadius = width > height ? width / 2 : height / 2;
	float radius = CalculateRadius(GAME_WIDTH + objectRadius * 2.0f, GAME_HEIGHT + objectRadius * 2.0f);
	//Calculate position in sphere perimeter
	Vector2 perimeterPosition = CalculatePositionInRadius(radius);

	//Clamp to rectangle
	float halfHeight = (float)GAME_HEIGHT / 2.f + (float)objectRadius;
	float halfWidth = (float)GAME_WIDTH / 2.f + (float)objectRadius;

	perimeterPosition = ClampPositionToRectangle(perimeterPosition, halfWidth, halfHeight);

	position = perimeterPosition;
	position = position + Vector2(halfWidth, halfHeight);
	rotation = rand() % 360;
	scale = Vector2(1.0f, 1.0f);

	acceleration = Vector2(0, 0);
	angularAcceleration = 0.f;
	linearDrag = 0.f;
	angularDrag = 0.f;

	angularVelocity = 100 - rand() % 201;
	velocity = CalculatePositionInRadius(100);
}
