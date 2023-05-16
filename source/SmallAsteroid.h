#pragma once

#include "Asteroid.h"

class SmallAsteroid : public Asteroid {

public:
	SmallAsteroid(SDL_Renderer* rend, Vector2 pos);
};