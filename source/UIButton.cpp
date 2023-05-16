#include "UIButton.h"

void UIButton::GenerateTexture(SDL_Renderer* rend)
{
	txt->GenerateTexture(rend);
	texture = SDL_CreateTexture(rend, 0, 0, width, height);
}

void UIButton::Update(float dt)
{
	if (CheckPointInsideCenteredRectangle(Vector2(IM.GetMouseX(), IM.GetMouseY()), position, width, height)) hoovering = true;
	else hoovering = false;
	txt->Update(dt);
}

void UIButton::Render(SDL_Renderer* rend)
{
	txt->Render(rend);
	SDL_Rect dest{
		position.x - (int)((float)width * scale.x / 2),
		position.y - (int)((float)height * scale.y / 2),
		(float)width * scale.x,
		(float)height * scale.y
	};
	SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
	if (hoovering) SDL_SetRenderDrawColor(rend, myColor2.r, myColor2.g, myColor2.b, 0x55) ;
	else SDL_SetRenderDrawColor(rend, myColor.r, myColor.g, myColor.b, myColor.a);

	if (hoovering) SDL_RenderFillRect(rend, &dest);
	else SDL_RenderDrawRect(rend, &dest);
}
