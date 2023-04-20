#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer)
{
	position = Vector2();
	rotation = 0.f;
	scale = Vector2(1.f, 1.f);

	SDL_Surface* surf = IMG_Load("resources/asteroids_spritesheet.png");
	if (!surf) cout << "Error load surface: " << SDL_GetError();

	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (!texture) cout << "Error load texture: " << SDL_GetError();

	SDL_FreeSurface(surf);
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}

void GameObject::Update(float dt) {

}

void GameObject::Render(SDL_Renderer* renderer) {

	position = Vector2(100, 100);
	SDL_Rect source{ 0, 0, //top-left
					31, 39 };	//bottom-right
	SDL_Rect destination{ 
		position.x - (source.w * scale.x) / 2, 
		position.y - (source.h * scale.y) / 2,
		source.w * scale.x, 
		source.h * scale.y};

	rotation += 1;
	SDL_RenderCopyEx(renderer, texture, &source, &destination, rotation, NULL, SDL_FLIP_NONE);
}
