#include "stdafx.h"
#pragma once

#include "HumanPlayer.h"
#include <conio.h>
#include "IllegalMoveException.h"

void HumanPlayer::playGame() {
	// get char
	char desiredMove;
	bool isSolved = false;
	bool quittingGame = false;

	while(!isSolved && !quittingGame) {
		displayValidKeys();
		desiredMove = _getch();
		try {
			switch (desiredMove) {
			case 'w':
				isSolved = _gameController->makeMove(UP);
				break;
			case 'a':
				isSolved = _gameController->makeMove(LEFT);
				break;
			case 's':
				isSolved = _gameController->makeMove(DOWN);
				break;
			case 'd':
				isSolved = _gameController->makeMove(RIGHT);
				break;
			case 'e':
				quittingGame = true;
				break;
			default:
				cout << "You must press a valid key! Try again." << endl;
				displayValidKeys();
			}
		} catch (IllegalMoveException err) { 
			cout << "That move is not valid!";
			displayValidKeys();
		}
	}

	if(isSolved) {
		cout << "Congrats, you won the game!" << endl;
		system("pause");
	}

}

void HumanPlayer::displayValidKeys() {
	cout << "[W = UP] [A = LEFT] [S = DOWN] [D = RIGHT] [E = EXIT LEVEL]" << endl;
}