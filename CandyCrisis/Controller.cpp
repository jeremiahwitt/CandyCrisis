#include "stdafx.h"
#include "Controller.h"

/**
 * Public Constructor. Sets up the GameBoard to be used by this controller.
 */
Controller::Controller(GameBoard* theGame) {
	_board = theGame;
	_board->printCurrentConfiguration();
}

/**
 * Will attempt to make a move requested by the user. If the move is successful, this method
 * will return whether or not the board has been solved. If the move is invalid, then an
 * exception will get thrown up to the caller.
 * @param direction - the MovementDirection the player wants to move the empty square in
 * @return bool - True of the game is solved, False otherwise
 */
bool Controller::makeMove(MovementDirection direction) {
	bool isSolved = false;
	switch(direction) {
	case UP:
		isSolved = _board->move_E_up();
		break;
	case DOWN:
		isSolved = _board->move_E_down();
		break;
	case LEFT:
		isSolved = _board->move_E_left();
		break;
	case RIGHT:
		isSolved = _board->move_E_right();
		break;
	}
	_board->printCurrentConfiguration();

	return isSolved;
}
