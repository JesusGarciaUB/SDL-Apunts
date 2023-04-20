#pragma once
#include <SDL.h>
#include <unordered_map>

using namespace std;
enum KeyState {EMPTY, DOWN, UP, HOLD};

#define IM InputManager::Instance()

class InputManager {
public:
	static InputManager& Instance() {
		static InputManager manager;
		return manager;
	}
	InputManager(const InputManager&) = delete;
	InputManager& operator = (const InputManager&) = delete;

	void Listen();
	bool GetKey(Sint32 key, KeyState state) { return keys[key] == state; }
	int GetMouseX() { return mouseX; }
	int GetMouseY() { return mouseY; }
	bool GetLeftClick() { return leftClick; }
	bool GetQuit() { return quit; }

private:
	InputManager() { quit = false; }

	//Keys and mouse
	unordered_map<Sint32, KeyState> keys;
	int mouseX, mouseY;
	bool leftClick;
	bool quit;
};