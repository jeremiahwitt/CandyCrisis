#include "stdafx.h"
#pragma once
#include "Controller.h"

/**
* Public Constructor. Sets up the GameBoard to be used by this controller and the solution path, as well as the view for the GameBoard
*/
Controller::Controller(GameBoard* theGame, GameView* theView) {
	_view = theView;
	_board = theGame;
	_board->printCurrentConfiguration();
	_solutionPathString = "";
}

/**
 * Public Constructor. Sets up the GameBoard to be used by this controller and the solution path.
 */
Controller::Controller(GameBoard* theGame, milliseconds startTime) {
	_board = theGame;
	_board->printCurrentConfiguration();
	_solutionPathString = "";
	_startTime = startTime;
}

void Controller::setIsHuman(bool isHuman) {
	_isHuman = isHuman;
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

	// Try to move in the direction that the user requested.
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

	_solutionPathString = _solutionPathString + (char) _board->get_E_Location() + " ";
	if(_isHuman || isSolved) {
		if(isSolved && !_isHuman) {
			milliseconds endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
			_board->printCurrentConfiguration();
			cout << "Took " << (endTime - _startTime).count() << " ms" << endl;
		}
		cout << "The moves so far are " << _solutionPathString << endl;
	}

	// TODO for printing out to file
	// 1 - grab time
	// 2 - calc diff
	// 4 - output to screen the solution path
	// 5 - !append! to the file the solution path and the time

	return isSolved;
}

/**
 * Returns a string representing the solution path thus far. This is the sequence of squares
 * that the blank/empty square has gone to!
 */
string Controller::getSolutionPath() {

	return _solutionPathString;
}
