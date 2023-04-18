#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer)
{
	position = Vector2();
	rotation = 0.f;
	scale = Vector2(1.f, 1.f);

	SDL_Surface* surf = IMG_Load("resources/obama.png");
	if (!surf) cout << "Error load surface: " << SDL_GetError();

	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (!texture) cout << "Error load texture: " << SDL_GetError();

	SDL_FreeSurface(surf);
}

void GameObject::Update(float dt) {

}

void GameObject::Render(SDL_Renderer* renderer) {
	SDL_Rect source{ 0, 0, 2687/5, 3356/5 };
	SDL_Rect destination{ position.x, position.y, source.w * scale.x, source.h * scale.y };
	SDL_RenderCopy(renderer, texture, &source, &destination);
}
