#include "stdafx.h"
#pragma once

#include "AIPlayer.h"
#include "AIBoardNode.h"
#include <conio.h>
#include <unordered_map>
#include <unordered_set>
#include "IllegalMoveException.h"
#include "AIPlayerUtilities.h"
#include <queue>
#include <functional>
#include <stack>

using namespace std;

void AIPlayer::playGame() {
	// Create the :
	// - closed list
	// - set of items on the open list
	// - open list priority queue
	unordered_map<long long int, AIBoardNode*>* closedList = new unordered_map<long long int, AIBoardNode*>();
	unordered_set<long long int>* openListSet = new unordered_set<long long int>();
	priority_queue<AIBoardNode*, vector<AIBoardNode*>, CompareNodes>* openList = new priority_queue<AIBoardNode*, vector<AIBoardNode*>, CompareNodes>(); // TODO maybe have to change this to AIBoardNode*
	stack<MovementDirection>* winningMovements = new stack<MovementDirection>();

	// Get the board string from the Controller and turn it into a number
	GameBoard* board = this->_gameController->getGameBoard();
	string boardContents = board->getBoardString();
	long long int numericalBoard = AIPlayerUtilities::generateNumericalBoard(boardContents);

	// Also get the e location!
	int e_HorizPosition = board->get_E_HorizontalPosition();
	int e_VertPosition = board->get_E_VerticalPosition();

	// Create the first node, put it on the open list
	AIBoardNode* initialNode = new AIBoardNode(nullptr, UP, this->_gameController->getDifficulty(), e_VertPosition, e_HorizPosition, numericalBoard);
	openListSet->insert(numericalBoard);
	openList->push(initialNode);

	// Loop through open list
	AIBoardNode* nextNode;
	while(!openList->empty()) {
		// Get the next node, check if it is the solution
		nextNode = openList->top();
		if(nextNode->isSolution()) {
			// Generate the stack of all the moves that generated the solution!
			AIBoardNode* backPedalNode = nextNode;
			while(backPedalNode->getParent() != nullptr) {
				winningMovements->push(backPedalNode->getMovementGeneratedBy());
				backPedalNode = backPedalNode->getParent();
			}
			break;
		}
		
		// Remove the node from the open list and add it to the closed list
		openList->pop();
		closedList->emplace(nextNode->getBoardState(), nextNode);
		openListSet->erase(nextNode->getBoardState());

		// Generate all the possible children, and add them to the open list if they're not explored
		MovementDirection possibleMoves[] = { UP, DOWN, LEFT, RIGHT };
		for(int i = 0; i < 4; i++) {
			if(nextNode->canMove(possibleMoves[i])) {
				AIBoardNode* child = nextNode->generateChildFromMovement(possibleMoves[i]);
				long long int boardState = child->getBoardState();
				if(openListSet->find(boardState) == openListSet->end() && closedList->find(boardState) == closedList->end()) {
					openListSet->insert(boardState);
					openList->push(child);
				} else {
					delete child;
				}
			}
		}
	}

	// Once the solution is found, we should have a stack of moves to make
	// Pop the moves off, and provide them to the game controller, one by one

	try {
		while (!winningMovements->empty()) {
			_gameController->makeMove(winningMovements->top());
			winningMovements->pop();
		}
	} catch (IllegalMoveException err) {
		cout << "The AI player made an illegal move and LOST the game." << endl;
		throw err;
	} 

	// Make sure that everything that should be deleted, gets deleted!
	delete winningMovements;
	delete closedList;
	delete openListSet;
	delete openList;
}
