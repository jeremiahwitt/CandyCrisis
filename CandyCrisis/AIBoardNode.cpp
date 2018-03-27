#include "stdafx.h"
#include "AIBoardNode.h"


AIBoardNode::AIBoardNode(AIBoardNode* parentNode, MovementDirection movementGeneratedBy, int diff,
	int eVertLocation, int eHorizLocation, long long int boardState) {
	this->_parentNode = parentNode;
	this->_movementGeneratedBy = movementGeneratedBy;
	this->_eVerticalLocation = eVertLocation;
	this->_eHorizontalLocation = eHorizLocation;
	this->_boardState = boardState;
	this->_difficulty = diff;

	// Set the depth based on the parent node!
	if (_parentNode == nullptr) {
		_depth = 0;
	} else {
		_depth = _parentNode->depth() + 1;
	}

	this->calculateHeuristicValue();
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

	// Perform the swapping!
	if(direction == UP || direction == DOWN) {
		rows[newEVertLocation] -= swappedSymbol * pow(10, 4 - newEHorizLocation);
		rows[_eVerticalLocation] += swappedSymbol * pow(10, 4 - newEHorizLocation);
	} else {
		rows[_eVerticalLocation] = rows[_eVerticalLocation] + (swappedSymbol * pow(10, 4 - _eHorizontalLocation)) - (swappedSymbol * pow(10, 4 - newEHorizLocation));
	}

	// Reconstruct the long long int from the sum of all the rows, times their respective isolator

	long long int newChildNode = rows[2] + (long long int) rows[1] * AIBoardNode::MIDDLE_ROW_ISOLATOR + (long long int) rows[0] * AIBoardNode::TOP_ROW_ISOLATOR;
	return new AIBoardNode(this, direction, newEVertLocation, newEHorizLocation, newChildNode);
}


/**
 * Internal method to calculate and set the heuristic value of this node!
 * 
 * For now, this is equal to the number of mismatched cells
 */
void AIBoardNode::calculateHeuristicValue() {
	int topRow = _boardState / TOP_ROW_ISOLATOR;
	int middleRow = (_boardState - (topRow * TOP_ROW_ISOLATOR)) / MIDDLE_ROW_ISOLATOR;
	int bottomRow = _boardState - (topRow * TOP_ROW_ISOLATOR) - (middleRow * MIDDLE_ROW_ISOLATOR);
	int countMismatched = 0;

	// Iterate over each of the cells, and count the ones that don't match!
	int topCell;
	int bottomCell;

	for(int i = 0; i < 5; i++) {
		topCell = (int)(topRow / pow(10, 4 - i)) % 10;
		bottomCell = (int)(bottomRow / pow(10, 4 - i)) % 10;
		

		if(topCell != bottomCell) {
			if(topCell > bottomCell) {
				countMismatched += weightBasedOnDifficulty(topCell);
			} else {
				countMismatched += weightBasedOnDifficulty(bottomCell);
			}
		}
	}

	this->_heuristicValue = countMismatched;
}

int AIBoardNode::weightBasedOnDifficulty(int cellValue) {
	switch(this->_difficulty) {
	case 1:
		if(cellValue == 3) {
			return 2;
		} else {
			return 1;
		}
	case 2:
		if(cellValue >= 3) {
			return 3;
		} else if (cellValue == 2) {
			return 2;
		} else {
			return 1;
		}
	case 3:
		if(cellValue >=3) {
			return 2;
		} else {
			return 1;
		}
	case 4:
		if(cellValue >=2) {
			return 2;
		} else {
			return 1;
		}
	default:
		return 1;
	}
}


/**
 * This method checks if the AIBoardNode represents a solved game. Takes advantage of the fact that the heuristic value,
 * at the moment, will be 0 if the game is solved!
 */
bool AIBoardNode::isSolution() {
	// TODO, if the heuristic calculation changes, may need to fix this!
	return _heuristicValue == 0;
}


