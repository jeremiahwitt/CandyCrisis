#include "stdafx.h"
#include "AIBoardNode.h"
#include <list>

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
	int heuristic = 0;

	// Before we waste time doing anything else, lets make sure that top != bottom
	if(topRow == bottomRow) {
		this->_heuristicValue = heuristic;
		return;
	}

	// Okay, so top != bottom. Lets setup for the search for closest match now!
	std::list<int> *locations[7];

	for(int i = 0; i < 7; i++) {
		locations[i] = new std::list<int>();
	}

	// Now we have all of our lists, lets set the location of each kind of cell in the middle row
	int cell;
	for(int i = 0; i < 5; i++) {
		// We're going to add the location of each kind of symbol to the lists of locations
		cell = (int)(middleRow / pow(10, 4 - i)) % 10;
		locations[cell]->push_back(i);
	}

	// Iterate over each of the cells, and count the ones that don't match!
	int topCell;
	int bottomCell;

	for(int i = 0; i < 5; i++) {
		topCell = (int)(topRow / pow(10, 4 - i)) % 10;
		bottomCell = (int)(bottomRow / pow(10, 4 - i)) % 10;
		

		if (topCell != bottomCell) {

			// GET TOP DISTANCE
			int topDistance = 3; // TODO could be adjusted!
			std::list<int>::iterator loc = locations[topCell]->begin();
			while (loc != locations[topCell]->end()) {
				int newDist = abs(i - *loc);
				if (newDist < topDistance) {
					topDistance = newDist;
				}
				++loc;
			}

			// GET BOTTOM DISTANCE
			int bottomDistance = 3; // TODO could be adjusted!
			loc = locations[bottomCell]->begin();
			while (loc != locations[bottomCell]->end()) {
				int newDist = abs(i - *loc);
				if (newDist < bottomDistance) {
					bottomDistance = newDist;
				}
				++loc;
			}

			// Now, see which one is better, and we'll favour that!
			if(topDistance < bottomDistance) {
				heuristic += topDistance + 1;
			} else {
				heuristic += bottomDistance + 1;
			}

			/*
			// Whichever is the max, add a little weight based on rarety
			if(topCell > bottomCell) {
				countMismatched += topCell;
			} else {
				countMismatched += bottomCell;
			}*/
			//countMismatched++;
		}
	}

	//this->_heuristicValue = countMismatched;
	this->_heuristicValue = heuristic;

	for(int i = 0; i < 5; i++) {
		delete locations[i];
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


