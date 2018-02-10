#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "MovementDirection.h"
#include "GameBoard.h"
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
	bool makeMove(MovementDirection direction);
	string getSolutionPath();
	~Controller() { delete _board; }

private:
	GameBoard* _board;
	string _solutionPathString;
	// TODO add a view!
};
#endif