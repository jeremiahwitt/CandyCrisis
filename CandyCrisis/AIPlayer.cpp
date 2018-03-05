#include "stdafx.h"
#pragma once

#include "AIPlayer.h"
#include <conio.h>
#include "IllegalMoveException.h"
#include "AIPlayerUtilities.h"

void AIPlayer::playGame() {
	// Get the board string from the Controller and turn it into a number
	GameBoard* board = this->_gameController->getGameBoard();
	string boardContents = board->getBoardString();
	long long int numericalBoard = AIPlayerUtilities::generateNumericalBoard(boardContents);

	// Also get the e location!
	int e_HorizPosition = board->get_E_HorizontalPosition();
	int e_VertPosition = board->get_E_VerticalPosition();

	// Create the first node, put it on the open list

	// Loop through open list
	// If the node is solution, then generate stack of moves to use
	// If the node is not the solution, generate all the children that are new and put them on the open list

	// Once the solution is found, we should have a stack of moves to make
	// Pop the moves off, and provide them to the game controller, one by one
}
