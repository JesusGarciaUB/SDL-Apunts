#pragma once
#include <vector>
#include "GameObject.h"
#include <SDL.h>
#include "InputManager.h"

using namespace std;

class Scene {
public:
	Scene() = default;

	virtual void Start(SDL_Renderer* rend) { finished = false; }
	virtual void Update(float dt) { for (auto it = objects.begin(); it != objects.end(); it++) (*it)->Update(dt); }
	virtual void Render(SDL_Renderer* rend) { for (auto it = objects.begin(); it != objects.end(); it++) (*it)->Render(rend); }
	virtual void Exit() = 0;
	bool IsFinished() { return finished; }
	string GetTargetScene() { return targetScene; }

protected:
	vector<GameObject*> objects;

	bool finished = false;
	string targetScene;
};