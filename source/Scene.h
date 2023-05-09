#pragma once
#include <vector>
#include "GameObject.h"
#include <SDL.h>
#include "InputManager.h"
#include "UIObject.h"

class Scene {
public:
	Scene() = default;

	virtual void Start(SDL_Renderer* rend) { finished = false; }
	virtual void Update(float dt) { 

		for (int x = objects.size() - 1; x >= 0; x--) {
			if (objects[x]->IsPendingDestroy()) {
				delete objects[x];
				objects.erase(objects.begin() + x);
			}
		}

		for (auto it = objects.begin(); it != objects.end(); it++) (*it)->Update(dt); 
		for (auto it = uiObjects.begin(); it != uiObjects.end(); it++) (*it)->Update(dt);
	}
	virtual void Render(SDL_Renderer* rend) { 
		for (auto it = objects.begin(); it != objects.end(); it++) (*it)->Render(rend);
		for (auto it = uiObjects.begin(); it != uiObjects.end(); it++) (*it)->Render(rend);
	}
	virtual void Exit() = 0;
	bool IsFinished() { return finished; }
	std::string GetTargetScene() { return targetScene; }

protected:
	std::vector<GameObject*> objects;
	std::vector<UIObject*> uiObjects;

	bool finished = false;
	std::string targetScene;
};