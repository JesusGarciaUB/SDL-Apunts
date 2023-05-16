#pragma once
#include "UIText.h";
#include "UIImage.h";
#include "InputManager.h"
#include "Utils.h"

class UIButton : public UIObject {
private:
	void GenerateTexture(SDL_Renderer* rend) override;
	bool hoovering;
public:
	UIButton(SDL_Renderer* rend, Vector2 pos, float rot, Vector2 scl, UIText* myText, int w, int h) : UIObject(rend, pos, rot, scl) {
		txt = myText;
		width = w;
		height = h;
		GenerateTexture(rend); 
	}

	UIText* txt;
	void Update(float dt) override;
	void Render(SDL_Renderer* rend) override;
	SDL_Color myColor{ 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Color myColor2{ 0xFF, 0xFF, 0xFF, 0x01 };
};