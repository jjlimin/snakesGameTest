#pragma once

#include "point.h"
#include "gameConfig.h"

class Snake
{
	Point body[GameConfig::SNAKE_SIZE];
	char ch;
	int backgroundColor;

public:

	Snake(const Point& head = Point(), char ch = ' ', int backgroundColor = GameConfig::COLORS[0]);
	void move(GameConfig::ekeys direction);
};

