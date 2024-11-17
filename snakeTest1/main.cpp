// EXTERNAL LIBRARIES
#include <Windows.h>

// INTERNAL LIBRARIES
#include "snakesGame.h"
#include "gameConfig.h"
#include "general.h"

// MAIN
int main() {
	SnakesGame game(9);
	game.run();
	game.freeMemory();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[0]);
	gotoxy(0, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y + 2);

}