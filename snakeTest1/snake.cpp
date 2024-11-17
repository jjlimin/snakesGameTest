#include "snake.h"
#include "gameConfig.h"
#include "point.h"


Snake::Snake(const Point& head, char ch, int backgroundColor) {
	
	this->ch = ch;
	this->backgroundColor = backgroundColor;
	
	body[0] = head;

	body[0].draw(ch, backgroundColor);

	for (int i = 1; i < GameConfig::SNAKE_SIZE; i++) {
		body[i] = body[i - 1];
		body[i].move((GameConfig::ekeys)0);
		body[i].draw(ch, backgroundColor);
	}
}

void Snake::move(GameConfig::ekeys direction) {
	// color the tail black
	body[GameConfig::SNAKE_SIZE - 1].draw(' ', GameConfig::COLORS[0]);

	for (int i = GameConfig::SNAKE_SIZE - 1; i > 0; i--)
		body[i] = body[i - 1];

	body[0].move(direction);
	body[0].draw(ch, backgroundColor);
}