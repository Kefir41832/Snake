#pragma once
#include "Snake.h"
#include <ctime>
// #include <iostream>
#include <string>
#include "ncurses_wrapper.h"
class Game
{
public:
	Game();
	void updateMap();
	void drawMap() const;
	void logicGame();
	bool isSnakeRivaled() const;
	bool isSnakeAte() const;
	void statusGame();

private:
	short _score;
	char _statusGame, _direction;
	bool _isDefeat;
	std::pair<short, short> _eat, _newTail;
	static const short _rows = 18, _cols = 12;
	char _map[_rows][_cols];
	Snake _snake;
};