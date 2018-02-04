#include "stdafx.h"
#include <vector>
#include <ctime>
#include <iostream> //TODO remove this!
#include "RandomConfigurator.h"
using namespace std;


/**
* Constructs a RandomConfigurator with the desired difficulty level.
*/
RandomConfigurator::RandomConfigurator(int difficultyLevel) {
	this->_difficultyLevel = difficultyLevel;
}

/**
* Returns a string that can be used to construct a GameBoard, with the right amount of characters based
* upon the desired difficulty level.
*/
string RandomConfigurator::getGameBoard() {
	srand(time(NULL));
	vector<char> charsToBeUsed = _getCharsForLevel();

	for (int i = 0; i < 15; i++) {
		cout << charsToBeUsed.at(i);
	}

	string gameboard = "";

	// Remove each char one by one, and add it to the game board. We will select a random char each time
	for (int i = 0; i < BOARD_SIZE; i++) {
		int randomIndex = rand() % charsToBeUsed.size();
		cout << randomIndex + " " + i + '\n';

		gameboard += charsToBeUsed.at(randomIndex);
		charsToBeUsed.erase(charsToBeUsed.begin() + randomIndex); // Remove the element that we just grabbed
	}

	return gameboard;
}

/**
* Sets up a vector containing all the chars that can be used to generate the gameboard, based
* on the level of difficulty to be used.
*/
vector<char> RandomConfigurator::_getCharsForLevel() {
	vector<char> charsToBeUsed(BOARD_SIZE);

	switch (_difficultyLevel) {
	case 1: charsToBeUsed = { 'r', 'r', 'r', 'r', 'r', 'r', 'b', 'b', 'b', 'b', 'b', 'b', 'w', 'w', 'e' };
			break;
	case 2: charsToBeUsed = { 'r', 'r', 'r', 'r', 'r', 'r', 'b', 'b', 'b', 'b', 'w', 'w', 'y', 'y', 'e' };
			break;
	case 3: charsToBeUsed = { 'r', 'r', 'r', 'r', 'b', 'b', 'b', 'b', 'w', 'w', 'y', 'y', 'g', 'g', 'e' };
			break;
	case 4: charsToBeUsed = { 'r', 'r', 'r', 'r', 'b', 'b', 'w', 'w', 'y', 'y', 'g', 'g', 'p', 'p', 'e' };
			break;
	}

	return charsToBeUsed;
}





