#pragma once
#include "UIObject.h"
#include "SDL_ttf.h"
#include <iostream>

class UIText : public UIObject {
public:
	UIText(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, std::string txt, std::string path) : UIObject(rend, pos, rot, scl), text(txt), fontPath(path), renderer(rend) { GenerateTexture(rend); }

	void Update(float dt) override {}
	void Render(SDL_Renderer* rend) override;
	void ChangeText(std::string newText) { SDL_DestroyTexture(texture); text = newText; GenerateTexture(renderer); }

protected:
	void GenerateTexture(SDL_Renderer* rend) override;
	std::string text;
	std::string fontPath;
	SDL_Renderer* renderer;
};