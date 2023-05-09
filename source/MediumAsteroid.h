#pragma once

#include "Asteroid.h"

class MediumAsteroid : public Asteroid {

public:
	MediumAsteroid(SDL_Renderer* rend, Vector2 pos, int vel);
};