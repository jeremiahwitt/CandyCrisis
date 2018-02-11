#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "stdafx.h"
#include "Subject.h"
using namespace std;
/**
 * @class Gameboard
 * @brief Represents the board of the game. Holds information about what Candy is at which tile. 
 *		  Provides methods which allow for manipulation of the tiles, as well as a way to determine
 *		  if the game has been solved.
 */
class GameBoard : public Subject {
public:
	static const int TOP_ROW = 0;
	static const int MIDDLE_ROW = 1;
	static const int BOTTOM_ROW = 2;
	static const int NUM_ROWS = 3;
	static const int NUM_COLUMNS = 5;
	static const int NUM_TILES = NUM_ROWS * NUM_COLUMNS;
	GameBoard(string contentsOfTheBoard);
	bool isSolved();
	bool move_E_left();
	bool move_E_right();
	bool move_E_down();
	bool move_E_up();
	char get_E_Location();
	char getTileAt(int verticalPos, int horizontalPos);
	void printCurrentConfiguration();
private:
	char _gameBoardContents[NUM_TILES];
	int _e_VerticalPosition;
	int _e_HorizontalPosition;
	static int _getIndexFromPosition(int vertPos, int horizPos);
	void _swapBasedOnIndices(int a, int b);
};

inline int GameBoard::_getIndexFromPosition(int vertPos, int horizPos) {
	return vertPos + (3 * horizPos);
}
#endif
