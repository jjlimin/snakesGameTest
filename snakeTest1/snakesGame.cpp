#include "snakesGame.h"
#include "snake.h"
#include "general.h"

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

using std::cout;

SnakesGame::SnakesGame(int num_of_snakes) {
    drawBoard();

    this->num_of_snakes = num_of_snakes;
    allSnakes = new Snake[num_of_snakes];

    for (int i = 0; i < num_of_snakes; i++) {
        Point head(rand() % GameConfig::GAME_WIDTH, rand() % GameConfig::GAME_HEIGHT);

        // Directly construct the Snake object in the array
        allSnakes[i] = Snake(head, ' ', GameConfig::COLORS[i % (GameConfig::NUM_OF_COLORS - 1) + 1]);
    }
}

void SnakesGame::freeMemory() {
	delete[]allSnakes;
}

void SnakesGame::drawBoard() {
	// draws up and down borders
	for (int col = GameConfig::MIN_X; col < GameConfig::GAME_WIDTH + GameConfig::MIN_X; col++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[9]);
		gotoxy(col, GameConfig::MIN_Y - 1);
		cout << " ";

		gotoxy(col, GameConfig::MIN_Y + GameConfig::GAME_HEIGHT);
		cout << " ";
	}

	// draws left and right borders
	for (int row = GameConfig::MIN_Y - 1; row <= GameConfig::GAME_HEIGHT + GameConfig::MIN_Y; row++) {
		gotoxy(GameConfig::MIN_X - 1, row);
		cout << " ";

		gotoxy(GameConfig::GAME_WIDTH + GameConfig::MIN_X, row);
		cout << " ";
	}
}

// game loop
void SnakesGame::run() {
	while (true) {
		int keyPressed = 0;
		if (_kbhit()) {
			keyPressed = _getch();
			if (keyPressed == (int)GameConfig::ekeys::ESC)
				break;
		}

		Sleep(350);
		for (int i = 0; i < num_of_snakes; i++)
			allSnakes[i].move((GameConfig::ekeys)keyPressed);
	}
}

