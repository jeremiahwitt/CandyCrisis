#include "stdafx.h"
#include "HumanPlayer.h"
#include <conio.h>

HumanPlayer::HumanPlayer(Controller* gameController) {
	_gameController = gameController;
}


void HumanPlayer::playGame() {
	// get char
	char desiredMove;
	bool isSolved = false;
	bool quittingGame = false;
	displayValidKeys();
	while(!isSolved && !quittingGame) {
		desiredMove = _getch();
		switch(desiredMove) {
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
		}
	}
	if(isSolved) {
		cout << "Congrats, you won the game!";
	}

}

void HumanPlayer::displayValidKeys() {
	cout << "[W = UP] [A = LEFT] [S = DOWN] [D = RIGHT] [E = QUIT]" << endl;
}

