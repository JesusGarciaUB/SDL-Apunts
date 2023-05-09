
#include "SmallAsteroid.h"

SmallAsteroid::SmallAsteroid(SDL_Renderer* rend, Vector2 pos, int vel)
:Asteroid(rend) {
	scale = scale / 2;

	velocity = velocity + Vector2(rand() % vel, rand() % vel);
}
