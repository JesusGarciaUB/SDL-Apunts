//#include <SDL.h>
#include "GameEngine.h"
#include <stdlib.h>
#include <time.h>
#include "Utils.h"

int SDL_main(int argc, char* argv[]) {
	srand(time(NULL));
	GameEngine engine(GAME_WIDTH, GAME_HEIGHT);
	engine.Update();
	engine.Finish();
	return 0;
}