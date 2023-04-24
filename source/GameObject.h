#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include <iostream>

using namespace std;

class GameObject {
public:
	GameObject(SDL_Renderer* renderer);
	~GameObject();
	virtual void Render(SDL_Renderer* renderer) = 0;
	virtual void Update(float dt) = 0;
protected:
	Vector2 position;
	float rotation;
	Vector2 scale;
	SDL_Texture* texture;
};