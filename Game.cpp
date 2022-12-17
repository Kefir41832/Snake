#include "Game.h"
Game::Game()
{
	_eat = {1 + rand() % (_rows - 2), 1 + rand() % (_cols - 2)};
	_newTail = _snake.GetBodySnake().front();
	_score = 0;
	_direction = 'd';
	_statusGame = 'p';
	_isDefeat = false;
}
void Game::updateMap()
{
	for (size_t i = 0; i < _rows; ++i)
	{
		for (size_t j = 0; j < _cols; ++j)
		{
			if (i == 0 || i == _rows - 1)
			{
				_map[i][j] = '-';
			}
			else if (j == 0 || j == _cols - 1)
			{
				_map[i][j] = '|';
			}
			else
			{
				_map[i][j] = ' ';
			}
		}
	}
	for (const auto &body : _snake.GetBodySnake())
	{
		_map[body.first][body.second] = char(4);
	}
	_map[_snake.GetHeadSnake().first][_snake.GetHeadSnake().second] = char(1);
	if (!isSnakeAte())
	{
		_map[_eat.first][_eat.second] = '*';
	}
}
void Game::drawMap() const
{
	std::string str;
	for (size_t i = 0; i < _rows; ++i)
	{
		for (size_t j = 0; j < _cols; ++j)
		{
			str += _map[i][j];
			str += ' ';
		}
		str += '\n';
	}
	printw("%s", str.c_str());
	// printw("%s", "Score: " + std::to_string(_score));
}
bool Game::isSnakeRivaled() const
{
	auto head = _snake.GetHeadSnake();
	if (head.first == 0 || head.first == _rows - 1 || head.second == 0 || head.second == _cols - 1)
	{
		return true;
	}
	else
	{
		for (const auto &body : _snake.GetBodySnake())
		{
			return {_snake.GetHeadSnake() == body};
		}
	}
	return false;
}
bool Game::isSnakeAte() const { return {_snake.GetHeadSnake() == _eat}; }
// void Game::statusGame()
// {
// 	initscr();
// 	curs_set(0);
// 	keypad(stdscr, true);
// 	_statusGame = getch();
// 	switch (_statusGame)
// 	{
// 	case ('p'):
// 	{
// 		system("cls");
// 		updateMap();
// 		drawMap();
// 		printw("%s", "\n Game on pause, press any key to continue!");
// 	}
// 	case (27):
// 	{
// 		_isDefeat = true;
// 		break;
// 	}
// 	default:
// 	{
// 		_direction = _statusGame;
// 		system("cls");
// 		if (isSnakeRivaled())
// 		{
// 			_isDefeat = true;
// 			printw("%s", "\nGame over, you lose!\n");
// 		}
// 		else
// 		{
// 			if (_snake.GetBodySnake().size() == (_rows - 2) * (_cols - 2) - 1)
// 			{
// 				_isDefeat = true;
// 				// printw("%s", "\nCongratulations! You win!" + std::to_string(_score) + "\n");
// 			}
// 			else
// 			{
// 				if (isSnakeAte())
// 				{
// 					_score += 10;
// 					_eat = {1 + rand() % (_rows - 2), 1 + rand() % (_cols - 2)};
// 					_newTail = _snake.GetBodySnake().front();
// 					_snake.updateCoordSnake(_direction);
// 					_snake.snakeBodyIncrement(_newTail);
// 				}
// 				else
// 				{
// 					_snake.updateCoordSnake(_direction);
// 				}
// 			}
// 		}
// 		updateMap();
// 		drawMap();
// 		sleep(200);
// 		break;
// 	}
// 	}
// }
void Game::logicGame()
{
	initscr();
	curs_set(0);
	noecho();
	updateMap();
	drawMap();
	// do
	// {
	// 	//statusGame();
	// } while (!_isDefeat);
	printw("%s", "\nPress any key to exit the game.");
	getch();
	endwin();
}