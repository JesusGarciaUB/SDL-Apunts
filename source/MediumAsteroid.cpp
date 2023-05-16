#include "MediumAsteroid.h"

MediumAsteroid::MediumAsteroid(SDL_Renderer* rend, Vector2 pos)
	:Asteroid(rend) {
	
	int random = rand() % 2;
	switch (random) {
	case 0:
		width = 37;
		height = 36;
		padding = Vector2(41, 3);
		break;
	case 1:
		width = 43;
		height = 38;
		padding = Vector2(81, 2);
		break;
	}

	position = pos;
	angularVelocity = 70 - rand() % 141;
	velocity = CalculatePositionInRadius(70);
	radius = CalculateRadius(width, height);
}
