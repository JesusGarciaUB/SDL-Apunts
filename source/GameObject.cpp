#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer, int width, int height, Vector2 pa) : width(width), height(height), padding(pa)
{
	position = Vector2();
	rotation = 0.f;
	scale = Vector2(1.f, 1.f);

	radius = CalculateRadius(width, height);

	SDL_Surface* surf = IMG_Load("resources/asteroids_spritesheet.png");
	if (!surf) std::cout << "Error load surface: " << SDL_GetError();

	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (!texture) std::cout << "Error load texture: " << SDL_GetError();

	SDL_FreeSurface(surf);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}

void GameObject::Update(float dt)
{
	UpdateMovement(dt);
	ClampPosition();
}

void GameObject::Render(SDL_Renderer* renderer)
{
	SDL_Rect source{ padding.x, padding.y, width, height };
	SDL_Rect dest{
		position.x - (int)((float)source.w * scale.x / 2.0f),
		position.y - (int)((float)source.h * scale.y / 2.0f),
		(float)source.w * scale.x,
		(float)source.h * scale.y
	};

	SDL_RenderCopyEx(
		renderer, texture,
		&source, &dest,
		90.f + rotation,
		NULL, //NULL = centered
		SDL_FLIP_NONE);
}

void GameObject::ClampPosition() {

	float scaleWidth = (float)width * scale.x;
	float scaleHeight = (float)height * scale.y;
	int biggestAxis = scaleWidth > scaleHeight ? scaleWidth : scaleHeight;

	if (position.x > GAME_WIDTH + biggestAxis) position.x -= (GAME_WIDTH + biggestAxis * 2);
	if (position.y > GAME_HEIGHT + biggestAxis) position.y -= (GAME_HEIGHT + biggestAxis * 2);

	if (position.x < 0 - biggestAxis) position.x += (GAME_WIDTH + biggestAxis * 2);
	if (position.y < 0 - biggestAxis) position.y += (GAME_HEIGHT + biggestAxis * 2);
}

void GameObject::UpdateMovement(float dt) {
	//------------- UPDATE VELOCITY AND ANGULAR VELOCITY
	velocity = velocity + acceleration * dt;
	angularVelocity = angularVelocity + angularAcceleration * dt;

	//-------------DRAG
	velocity = velocity * (1 - linearDrag * dt);
	angularVelocity = angularVelocity * (1 - angularDrag * dt);

	//------------- UPDATE POSITION AND ROTATION
	position = position + velocity * dt;
	rotation = rotation + angularVelocity * dt;
}
