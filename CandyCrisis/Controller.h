#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "MovementDirection.h"
#include "GameBoard.h"

/**
 * @class Controller
 * @brief The Controller is in charge of 'controlling' the game. It takes requested moves from the Player, tries
 *        to change the state of the board.
 */
class Controller {
public:
	Controller(GameBoard* theGame);
	bool makeMove(MovementDirection direction);
	~Controller() { delete _board; }

private:
	GameBoard* _board;
	// TODO add a view!
};
#endif