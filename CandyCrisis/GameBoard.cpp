#pragma once
#include "stdafx.h"
#include "GameBoard.h"
#include "IllegalMoveException.h"
#include <thread>
using namespace std;

GameBoard::GameBoard(string contentsOfTheBoard) {
	
	// Setup the top row
	int rowOffset = 0;
	char  currentChar;
	for(int i = 0; i < NUM_COLUMNS; i++) {
		currentChar = contentsOfTheBoard.at(i);
		_gameBoardContents[_getIndexFromPosition(TOP_ROW, i - rowOffset)] = currentChar;
		if(currentChar == 'e'){
			_e_VerticalPosition = TOP_ROW;
			_e_HorizontalPosition = i - rowOffset;
		}
	}

	// Setup the middle row
	rowOffset = MIDDLE_ROW * NUM_COLUMNS;
	for(int i = 0 + rowOffset; i < (BOTTOM_ROW * NUM_COLUMNS); i++) {
		currentChar = contentsOfTheBoard.at(i);
		_gameBoardContents[_getIndexFromPosition(MIDDLE_ROW, i - rowOffset)] = currentChar;
		if (currentChar == 'e') {
			_e_VerticalPosition = MIDDLE_ROW;
			_e_HorizontalPosition = i - rowOffset;
		}
	}

	// Setup the bottom row
	rowOffset = BOTTOM_ROW * NUM_COLUMNS;
	for (int i = 0 + rowOffset; i < NUM_TILES; i++) {
		currentChar = contentsOfTheBoard.at(i);
		_gameBoardContents[_getIndexFromPosition(BOTTOM_ROW, i - rowOffset)] = currentChar;
		if (currentChar == 'e') {
			_e_VerticalPosition = BOTTOM_ROW;
			_e_HorizontalPosition = i - rowOffset;
		}
	}
}

/**
 * Can be used to determine if the GameBoard configuration is in a state where it has been solved.
 */
bool GameBoard::isSolved() {
	
	bool solved = true;
	// We'll first check to see if the 'e' is in the middle row. If it isn't, we automatically know the board is not solved.
	if(_e_VerticalPosition != MIDDLE_ROW) {
		solved = false;
		return solved;
	}

	// Now, check to see that all the symbols in the top row match the bottom row!
	for(int i = 0; i < NUM_COLUMNS; i++) {
		if(getTileAt(TOP_ROW, i) != getTileAt(BOTTOM_ROW, i)) {
			solved = false;
			break;
		}
	}
	
	return solved;
}

bool GameBoard::move_E_left() {
	if(_e_HorizontalPosition == 0) {
		// Cannot go any further left!
		throw IllegalMoveException();
	}

	int eIndex = _getIndexFromPosition(_e_VerticalPosition, _e_HorizontalPosition);
	int indexOfCharToBeSwapped = _getIndexFromPosition(_e_VerticalPosition, --_e_HorizontalPosition);
	_swapBasedOnIndices(eIndex, indexOfCharToBeSwapped);

	thread updateObservers(&Subject::notify, this);
	bool solved = isSolved();
	updateObservers.join();
	return solved;
}

bool GameBoard::move_E_right() {
	if (_e_HorizontalPosition == NUM_COLUMNS - 1) {
		// Cannot go any further right!
		throw IllegalMoveException(); 
	}
	int eIndex = _getIndexFromPosition(_e_VerticalPosition, _e_HorizontalPosition);
	int indexOfCharToBeSwapped = _getIndexFromPosition(_e_VerticalPosition, ++_e_HorizontalPosition);
	_swapBasedOnIndices(eIndex, indexOfCharToBeSwapped);
	
	thread updateObservers(&Subject::notify, this);
	bool solved = isSolved();
	updateObservers.join();
	return solved;
}

bool GameBoard::move_E_down() {
	if (_e_VerticalPosition == NUM_ROWS - 1) {
		// Cannot go any further down!
		throw IllegalMoveException();
	}

	int eIndex = _getIndexFromPosition(_e_VerticalPosition, _e_HorizontalPosition);
	int indexOfCharToBeSwapped = _getIndexFromPosition(++_e_VerticalPosition, _e_HorizontalPosition);
	_swapBasedOnIndices(eIndex, indexOfCharToBeSwapped);
	
	thread updateObservers(&Subject::notify, this);
	bool solved = isSolved();
	updateObservers.join();
	return solved;
}

bool GameBoard::move_E_up() {
	if (_e_VerticalPosition == 0) {
		// Cannot go any further ip!
		throw IllegalMoveException();
	}

	int eIndex = _getIndexFromPosition(_e_VerticalPosition, _e_HorizontalPosition);
	int indexOfCharToBeSwapped = _getIndexFromPosition(--_e_VerticalPosition, _e_HorizontalPosition);
	_swapBasedOnIndices(eIndex, indexOfCharToBeSwapped);
	
	thread updateObservers(&Subject::notify, this);
	bool solved = isSolved();
	updateObservers.join();
	return solved;
}

/**
 * Will provide an alphebetical char representing the current tile that the empty square is at.
 */
char GameBoard::get_E_Location() {
	if(_e_VerticalPosition == TOP_ROW) {
		switch(_e_HorizontalPosition) {
		case 0:
			return 'A';
		case 1:
			return 'B';
		case 2:
			return 'C';
		case 3:
			return 'D';
		case 4:
			return 'E';
		}
	} else if(_e_VerticalPosition == MIDDLE_ROW) {
		switch (_e_HorizontalPosition) {
		case 0:
			return 'F';
		case 1:
			return 'G';
		case 2:
			return 'H';
		case 3:
			return 'I';
		case 4:
			return 'J';
		}
	} else { // BOTTOM_ROW
		switch (_e_HorizontalPosition) {
		case 0:
			return 'K';
		case 1:
			return 'L';
		case 2:
			return 'M';
		case 3:
			return 'N';
		case 4:
			return 'O';
		}
	}

	// This point should not be reached
	throw 1;
	return 'Z';
}

/**
 * Returns the character at the specified location.
 * @param verticalPos - the row of the symbol
 * @param horizontalPos - the column of the symbol
 */
char GameBoard::getTileAt(int verticalPos, int horizontalPos) {
	return _gameBoardContents[_getIndexFromPosition(verticalPos, horizontalPos)];
}

/**
 * Does a little char-to-int conversation magic to in place swap two characters.
 * a = a + b
 * b = a - b => (a + b)  - b = a
 * a = a - b => (a + b) - a = b
 */
void GameBoard::_swapBasedOnIndices(int a, int b) {
	_gameBoardContents[a] += _gameBoardContents[b];
	_gameBoardContents[b] = _gameBoardContents[a] - _gameBoardContents[b];
	_gameBoardContents[a] = _gameBoardContents[a] - _gameBoardContents[b];
}

void GameBoard::printCurrentConfiguration() {
	system("CLS");
	// Print Top Row
	for(int i = 0; i < NUM_COLUMNS; i++) {
		cout << getTileAt(TOP_ROW, i) << " ";
	}
	cout << endl;
	// Print Middle Row
	for (int i = 0; i < NUM_COLUMNS; i++) {
		cout << getTileAt(MIDDLE_ROW, i) << " ";
	}
	cout << endl;
	// Print Bottom Row
	for (int i = 0; i < NUM_COLUMNS; i++) {
		cout << getTileAt(BOTTOM_ROW, i) << " ";
	}
	cout << endl;
}
