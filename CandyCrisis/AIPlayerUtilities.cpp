#include "stdafx.h"
#pragma once 
#include "AIPlayerUtilities.h"

/**
 * Returns the number associated with the character
 */
int AIPlayerUtilities::getNumericalCharacter(char c) {
	// Conver the char into its numerical value
	int numericalChar;
	switch(c) {
	case 'r':
		numericalChar = AIPlayerUtilities::REESE;
		break;
	case 'b':
		numericalChar = AIPlayerUtilities::BAZOOKA;
		break;
	case 'w':
		numericalChar = AIPlayerUtilities::WALNETTO;
		break;
	case 'y':
		numericalChar = AIPlayerUtilities::YORK;
		break;
	case 'g':
		numericalChar = AIPlayerUtilities::GOBSTOPPER;
		break;
	case 'p':
		numericalChar = AIPlayerUtilities::PEZ;
		break;
	default:
		numericalChar = 0;
		break;
	}

	return numericalChar;
}

/**
 * Will turn the gameboard into a long long int. This is done so that the AIPlayer can deal with
 * a numerical representation of the gameboard, which makes testing MUCH easier
 */
long long int AIPlayerUtilities::generateNumericalBoard(std::string boardString) {
	// Starting with last character, we add the val of the character times 10^i to the sum
	int lastIndex = boardString.length() - 1;
	long long int sum = 0;
	for(int i = 0; i < boardString.length(); i++) {
		// Grab the char
		char c = boardString.at(lastIndex - i);

		int charNum = getNumericalCharacter(c);
		sum += charNum * pow(10.0, i);
	}

	return sum;
}