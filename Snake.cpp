#include "Snake.h"
Snake::Snake() {
	_snake = { {2, 2}, {2, 3}, {2, 4} };
	_vectorDirection = { 0,0 };
	_lastDirection = { 0,1 };
}
void Snake::changeVectorDirection(char direction) {
	switch (direction) {
	case('a'): {_vectorDirection = { 0,-1 }; _lastDirection = { 0,-1 }; break; }
	case('d'): {_vectorDirection = { 0, 1 }; _lastDirection = { 0,1 }; break; }
	case('w'): {_vectorDirection = { -1, 0 }; _lastDirection = { -1,-0 }; break; }
	case('s'): {_vectorDirection = { 1, 0 }; _lastDirection = { 1,0 }; break; }
	default: {_vectorDirection = _lastDirection; break; }
	}
}
void Snake::updateCoordSnake(char direction) {
	changeVectorDirection(direction);
	_snake.push_back({ _snake.back().first + _vectorDirection.first, _snake.back().second + _vectorDirection.second});
	_snake.pop_front();
}