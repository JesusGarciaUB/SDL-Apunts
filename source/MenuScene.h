#pragma once
#include "Scene.h"
#include <SDL.h>
#include "UIImage.h"
#include "UIText.h"
#include "UIButton.h"

class MenuScene : public Scene {
public:
	MenuScene() : Scene() {}

	void Start(SDL_Renderer* rend) override;
	void Update(float dt) override;
private:
};