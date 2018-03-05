#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "MovementDirection.h"
#include "GameBoard.h"
#include "GameView.h"
#include <vector>

using namespace std;

/**
 * @class Controller
 * @brief The Controller is in charge of 'controlling' the game. It takes requested moves from the Player, tries
 *        to change the state of the board.
 */
class Controller {
public:
	Controller(GameBoard* theGame);
	Controller(GameBoard* theGame, GameView* theView);
	bool makeMove(MovementDirection direction);
	string getSolutionPath();
	GameBoard* getGameBoard() { return _board; }
	~Controller() { delete _board; delete _view; }

private:
	GameBoard* _board;
	string _solutionPathString;
	GameView* _view;
};
#endif