#pragma once
#include <vector>
#include <utility>
#include <deque>
#include <range/v3/all.hpp>
class Snake
{
public:
	Snake();
	void changeVectorDirection(char direction);
	auto GetBodySnake() const { return ranges::views::take(_snake, _snake.size() - 1); }
	auto GetHeadSnake() const { return _snake.back(); }
	void updateCoordSnake(char direction);
	void snakeBodyIncrement(const std::pair<short, short> &newTail) { _snake.push_front(newTail); }

private:
	std::pair<short, short> _vectorDirection, _lastDirection;
	std::deque<std::pair<short, short>> _snake;
};