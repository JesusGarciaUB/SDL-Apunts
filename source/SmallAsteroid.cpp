
#include "SmallAsteroid.h"

SmallAsteroid::SmallAsteroid(SDL_Renderer* rend, Vector2 pos)
:Asteroid(rend) {
	
	int random = rand() % 3;
	switch (random) {
	case 0:
		width = 19;
		height = 18;
		padding = Vector2(128, 1);
		break;
	case 1:
		width = 19;
		height = 21;
		padding = Vector2(128, 22);
		break;
	case 2:
		width = 21;
		height = 18;
		padding = Vector2(166, 105);
		break;
	}

	position = pos;
	angularVelocity = 100 - rand() % 201;
	velocity = CalculatePositionInRadius(100);
	radius = CalculateRadius(width, height);
}
