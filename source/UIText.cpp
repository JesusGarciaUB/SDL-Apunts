#include "UIText.h"

void UIText::Render(SDL_Renderer* rend) {
	SDL_Rect dest{
		position.x - (int)((float)width * scale.x / 2.0f),
		position.y - (int)((float)height * scale.y / 2.0f),
		(float)width * scale.x,
		(float)height * scale.y
	};

	SDL_RenderCopyEx(
		rend, texture,
		NULL, &dest,
		rotation,
		NULL, //NULL = centered
		SDL_FLIP_NONE);
}

void UIText::GenerateTexture(SDL_Renderer* rend) {
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 28);
	SDL_Color color{ 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), color);

	if (surf == nullptr) std::cout << "Something went wrong generating surface" << std::endl;

	texture = SDL_CreateTextureFromSurface(rend, surf);

	width = surf->w;
	height = surf->h;

	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}