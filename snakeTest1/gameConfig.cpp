#include "gameConfig.h"
#include <Windows.h>

const int GameConfig::COLORS[] = { 
	FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,	// BLACK
	96,														
	176, 
	224, 
	95, 
	23, 
	111, 
	143, 
	48, 
	59, 
	63
};

const int GameConfig::NUM_OF_COLORS = sizeof(COLORS) / sizeof(int);