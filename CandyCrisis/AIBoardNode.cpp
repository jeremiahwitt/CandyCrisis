#include "stdafx.h"
#include "AIBoardNode.h"

/**
 * Public Constructor which sets all the properties of the AIBoardNode
 */
AIBoardNode::AIBoardNode(AIBoardNode* parentNode, MovementDirection movementGeneratedBy,
	int eVertLocation, int eHorizLocation, long long int boardState) {
	this->_parentNode = parentNode;
	this->_movementGeneratedBy = movementGeneratedBy;
	this->_eVerticalLocation = eVertLocation;
	this->_eHorizontalLocation = eHorizLocation;
	this->_boardState = boardState;
}

bool AIBoardNode::canMove(MovementDirection direction) {
	switch(direction) {
	case UP:
		if(_eVerticalLocation == 0) {
			return false;
		} else {
			return true;
		}
	case DOWN:
		if(_eVerticalLocation == 2) {
			return false;
		} else {
			return true;
		}
	case LEFT:
		if(_eHorizontalLocation == 0) {
			return false;
		} else {
			return true;
		}
	case RIGHT:
		if(_eHorizontalLocation == 4) {
			return false;
		} else {
			return true;
		}
	}

	return false;
}

AIBoardNode* AIBoardNode::generateChildFromMovement(MovementDirection direction) {
	int newEVertLocation;
	int newEHorizLocation;
	long long int newBoardState;

	// Isolate all the rows so that we can work with them easily
	int topRow = _boardState / TOP_ROW_ISOLATOR;
	int middleRow = (_boardState - (topRow * TOP_ROW_ISOLATOR)) / MIDDLE_ROW_ISOLATOR;
	int bottomRow = _boardState - (topRow * TOP_ROW_ISOLATOR) - (middleRow * MIDDLE_ROW_ISOLATOR);
	int rows[] = {topRow, middleRow, bottomRow};

	// Setup new e locations
	switch(direction) {
	case UP:
		newEVertLocation = _eVerticalLocation - 1;
		newEHorizLocation = _eHorizontalLocation;
		break;
	case DOWN:
		newEVertLocation = _eVerticalLocation + 1;
		newEHorizLocation = _eHorizontalLocation;
		break;
	case LEFT:
		newEVertLocation = _eVerticalLocation;
		newEHorizLocation = _eHorizontalLocation - 1;
		break;
	case RIGHT:
		newEVertLocation = _eVerticalLocation;
		newEHorizLocation = _eHorizontalLocation + 1;
	}

	// Isolate the value to be removed
	int swappedSymbol = (int)(rows[newEVertLocation] / pow(10, 4 - newEHorizLocation)) % 10;

	// Subtract this value * correct power of 10 from the new e row
	rows[newEVertLocation] -= swappedSymbol * pow(10, 4 - newEHorizLocation);

	// Add it to the old e row
	rows[_eVerticalLocation] += swappedSymbol * pow(10, 4 - newEHorizLocation);

	// Reconstruct the long long int from the sum of all the rows, times their respective isolator
	return nullptr;
}


