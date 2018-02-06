#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

/**
 * @class Gameboard
 * @brief Represents the board of the game. Holds information about what Candy is at which tile. 
 *		  Provides methods which allow for manipulation of the tiles, as well as a way to determine
 *		  if the game has been solved.
 */
class GameBoard {
public:
	static const int TOP_ROW = 0;
	static const int MIDDLE_ROW = 1;
	static const int BOTTOM_ROW = 2;
	GameBoard(string contentsOfTheBoard);
	bool isSolved();
	bool move_E_left();
	bool move_E_right();
	bool move_E_down();
	bool move_E_up();
	char get_E_Location();
	char getTileAt(int verticalPos, int horizontalPos);
private:
	char _gameBoardContents;
	int _e_VerticalPosition;
	int _e_HorizontalPosition;
};

#endif