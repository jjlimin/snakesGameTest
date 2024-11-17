#include "point.h"
#include "general.h"
#include "gameConfig.h"

#include <iostream>
#include <Windows.h>

using std::cout;

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
	diff_x = 1;
	diff_y = 0;
}

void Point::draw(char ch, int backgroundColor) {
	// set background color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgroundColor);

	// set position and char
	gotoxy(x + GameConfig::MIN_X -1, y + GameConfig::MIN_Y - 1);
	cout << ch;
}

void Point::move(GameConfig::ekeys direction) {
	switch (direction) {
	case GameConfig::ekeys::LEFT:
		diff_x = -1;
		diff_y = 0;
		break;
	case GameConfig::ekeys::RIGHT:
		diff_x = 1;
		diff_y = 0;
		break;
	case GameConfig::ekeys::UP:
		diff_x = 0;
		diff_y = -1;
		break;
	case GameConfig::ekeys::DOWN:
		diff_x = 0;
		diff_y = 1;
		break;
	}

	x += diff_x;
	if (x > GameConfig::GAME_WIDTH)
		x = 1;
	else if (x == 0)
		x = GameConfig::GAME_WIDTH;

	y += diff_y;
	if (y > GameConfig::GAME_HEIGHT)
		y = 1;
	else if (y == 0)
		y = GameConfig::GAME_HEIGHT;

}
