#include "UIImage.h"

void UIImage::Render(SDL_Renderer* rend) {
	SDL_Rect source{ padding.x, padding.y, width, height };
	SDL_Rect dest{
		position.x - (int)((float)source.w * scale.x / 2.0f),
		position.y - (int)((float)source.h * scale.y / 2.0f),
		(float)source.w * scale.x,
		(float)source.h * scale.y
	};

	SDL_RenderCopyEx(
		rend, texture,
		&source, &dest,
		rotation,
		NULL, //NULL = centered
		SDL_FLIP_NONE);
}

void UIImage::GenerateTexture(SDL_Renderer* rend) {
	SDL_Surface* surf = IMG_Load(resourcePath.c_str());
	if (!surf) std::cout << "Error load surface: " << SDL_GetError();

	texture = SDL_CreateTextureFromSurface(rend, surf);
	if (!texture) std::cout << "Error load texture: " << SDL_GetError();

	SDL_FreeSurface(surf);
}