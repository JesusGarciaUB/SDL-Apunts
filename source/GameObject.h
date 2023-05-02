#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include <iostream>
#include "Utils.h"
#include <stdlib.h>

using namespace std;

class GameObject {
public:
	GameObject(SDL_Renderer* renderer, int width, int height, Vector2 pa);
	~GameObject();
	virtual void Render(SDL_Renderer* renderer);
	virtual void Update(float dt);

	virtual void Destroy() { pendingDestroy = true; }
	bool IsPendingDestroy() { return pendingDestroy; }
	Vector2 GetPosition() { return position; }
protected:
	//Flags
	bool pendingDestroy = false;

	virtual void UpdateMovement(float dt);

	//Transform
	Vector2 position;
	float rotation;
	Vector2 scale;

	//Render
	SDL_Texture* texture;
	int width, height;
	Vector2 padding;

	void ClampPosition();

	//Velocity
	Vector2 velocity;
	float angularVelocity;
	//Drag
	float linearDrag;
	float angularDrag;
	//Acceleration
	Vector2 acceleration;
	float angularAcceleration;
	float accelerationFactor;
	float angularAccelerationFactor;
};