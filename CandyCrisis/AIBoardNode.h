#pragma once
#ifndef AIBOARDNODE_H
#define AIBOARDNODE_H
#include "MovementDirection.h"

/**
 * This class will be used to represent a node in the AIPlayer's interpretation of the game board
 */
class AIBoardNode {
public:
	static const long TOP_ROW_ISOLATOR = 10000000000;
	static const long MIDDLE_ROW_ISOLATOR = 100000;
	AIBoardNode(AIBoardNode* parentNode, MovementDirection movementGeneratedBy, int eVertLocation, int eHorizLocation, long long int boardState);
	AIBoardNode* getParent() { return _parentNode; }
	int get_E_VerticalPosition() { return _eVerticalLocation; }
	int get_E_HorizontalPosition() { return _eHorizontalLocation; }
	MovementDirection getMovementGeneratedBy() { return _movementGeneratedBy; }
	long long int getBoardState() { return _boardState; }

	bool canMove(MovementDirection direction); // Will indicate if the AIPlayer can move in a specific direction from this AIBoardNode
	AIBoardNode* generateChildFromMovement(MovementDirection direction); // Will generate a child node from the given direction
	~AIBoardNode() { _parentNode = nullptr;  }
private:
	long long int _boardState; // Numerical representation of the board at this state
	int _eVerticalLocation;
	int _eHorizontalLocation;
	MovementDirection _movementGeneratedBy; // The direction of movement that generated this node
	AIBoardNode* _parentNode; // Pointer to the parent node that generated this one
};
#endif
