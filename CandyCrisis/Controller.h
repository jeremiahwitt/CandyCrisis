#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <chrono>
#include "MovementDirection.h"
#include "GameBoard.h"
#include "GameView.h"
#include <vector>

using namespace std;
using namespace std::chrono;

/**
 * @class Controller
 * @brief The Controller is in charge of 'controlling' the game. It takes requested moves from the Player, tries
 *        to change the state of the board.
 */
class Controller {
public:
	Controller(GameBoard* theGame, milliseconds startTime);
	Controller(GameBoard* theGame, GameView* theView);
	bool makeMove(MovementDirection direction);
	string getSolutionPath();
	void setIsHuman(bool isHuman);
	GameBoard* getGameBoard() { return _board; }
	~Controller() { delete _board; delete _view; }
	void setGameNumber(int game_number) {
		this->_gameNumber = game_number;
	}
	long long getDuration() { return duration; }

private:
	int _gameNumber;
	long long duration;
	milliseconds _startTime;
	GameBoard* _board;
	string _solutionPathString;
	GameView* _view;
	bool _isHuman;
};
#endif