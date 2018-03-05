#pragma once
#ifndef AIPLAYERUTILITIES_H
#define AIPLAYERUTILITIES_H

class AIPlayerUtilities {
public:

	// These values will be used to translate the string versions of the board into a number
	static const int REESE = 1;
	static const int BAZOOKA = 2;
	static const int WALNETTO = 3;
	static const int YORK = 4;
	static const int GOBSTOPPER = 5;
	static const int PEZ = 6;

	static int getNumericalCharacter(char c);
	static long long int generateNumericalBoard(std::string gameBoard);
};

#endif