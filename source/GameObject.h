#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include <iostream>

using namespace std;

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	void Render(SDL_Renderer* renderer);
	void Update(float dt);
private:
	Vector2 position;
	float rotation;
	Vector2 scale;
	SDL_Texture* texture;
};