#pragma once
class GameConfig
{
public:
	enum class ekeys {
		LEFT = 'a', 
		RIGHT = 'd',
		UP = 'w',
		DOWN = 's', 
		ESC = 27
	};

	static constexpr int SNAKE_SIZE = 10;

	static constexpr int GAME_WIDTH = 80;
	static constexpr int GAME_HEIGHT = 20;

	static constexpr int MIN_X = 20;
	static constexpr int MIN_Y = 2;

	static const int COLORS[];
	static const int NUM_OF_COLORS;

};

