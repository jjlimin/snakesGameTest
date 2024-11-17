#pragma once

#include "gameConfig.h"

class Point
{
	int x;
	int y;
	int diff_x;
	int diff_y;

public:
	Point(int x = 1, int y = 1);
	void draw(char ch, int backgroundColor);
	void move(GameConfig::ekeys direction);
};

