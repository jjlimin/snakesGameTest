#pragma once
class Snake;

class SnakesGame
{
	Snake* allSnakes;
	int num_of_snakes;
	void drawBoard();
public:
	SnakesGame(int);
	void run();
	void freeMemory();
};

