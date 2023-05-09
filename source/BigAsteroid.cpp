#include "BigAsteroid.h"

BigAsteroid::BigAsteroid(SDL_Renderer* rend, float vel)
	:Asteroid(rend) {
	velocity = CalculatePositionInRadius(vel);
}