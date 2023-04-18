//#include <SDL.h>
#include "GameEngine.h"

int SDL_main(int argc, char* argv[]) {
	GameEngine engine(500, 500);
	engine.Update();
	engine.Finish();
	return 0;
}