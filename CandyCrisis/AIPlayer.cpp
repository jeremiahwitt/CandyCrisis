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

using namespace std;

void AIPlayer::playGame() {
	// Create the :
	// - closed list
	// - set of items on the open list
	// - open list priority queue
	unordered_map<long long int, AIBoardNode*>* closedList = new unordered_map<long long int, AIBoardNode*>();
	unordered_set<long long int>* openListSet = new unordered_set<long long int>();
	priority_queue<AIBoardNode*, vector<AIBoardNode*>, CompareNodes>* openList = new priority_queue<AIBoardNode*, vector<AIBoardNode*>, CompareNodes>(); // TODO maybe have to change this to AIBoardNode*

	// Get the board string from the Controller and turn it into a number
	GameBoard* board = this->_gameController->getGameBoard();
	string boardContents = board->getBoardString();
	long long int numericalBoard = AIPlayerUtilities::generateNumericalBoard(boardContents);

	// Also get the e location!
	int e_HorizPosition = board->get_E_HorizontalPosition();
	int e_VertPosition = board->get_E_VerticalPosition();

	// Create the first node, put it on the open list
	AIBoardNode* initialNode = new AIBoardNode(nullptr, UP, e_VertPosition, e_HorizPosition, numericalBoard);
	openListSet->insert(numericalBoard);
	openList->push(initialNode);

	// Loop through open list
	while(!openList->empty()) {
		// If the node is solution, then generate stack of moves to use
		// If the node is not the solution, generate all the children, and if they are not in open OR closed, then put in the closed list
	}


	// Once the solution is found, we should have a stack of moves to make
	// Pop the moves off, and provide them to the game controller, one by one

	// TODO Make sure that everything that should be deleted, gets deleted!
}
