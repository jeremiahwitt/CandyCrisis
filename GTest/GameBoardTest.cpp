#include "pch.h"
#include "../CandyCrisis/GameBoard.cpp"
#include "../CandyCrisis/Subject.cpp"
#include "../CandyCrisis/Observer.h"


using namespace std;

// Test that the player can make a valid move up from the middle
TEST(GameBoardTest, TestValidUpMoveFromMiddle) {
	string gameboardString = "aaaaabbebbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_up();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::TOP_ROW, 2));
		ASSERT_EQ('a', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 2));
	} catch(IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move up from the bottom
TEST(GameBoardTest, TestValidUpMoveFromBottom) {
	string gameboardString = "aaaaabbbbbccecc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_up();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 2));
		ASSERT_EQ('b', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move down from the top
TEST(GameBoardTest, TestValidDownMoveFromTop) {
	string gameboardString = "aaeaabbbbbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_down();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 2));
		ASSERT_EQ('b', testBoard.getTileAt(GameBoard::TOP_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move down from the middle
TEST(GameBoardTest, TestValidDownMoveFromMiddle) {
	string gameboardString = "aaaaabbebbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_down();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 2));
		ASSERT_EQ('c', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move left in the top row
TEST(GameBoardTest, TestValidLeftMoveInTopRow) {
	string gameboardString = "aaeaabbbbbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_left();
		testBoard.printCurrentConfiguration();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::TOP_ROW, 1));
		ASSERT_EQ('a', testBoard.getTileAt(GameBoard::TOP_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move left in the middle row
TEST(GameBoardTest, TestValidLeftMoveInMiddleRow) {
	string gameboardString = "aaaaabbebbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_left();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 1));
		ASSERT_EQ('b', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move left in the bottom row
TEST(GameBoardTest, TestValidLeftMoveInBottomRow) {
	string gameboardString = "aaaaabbbbbccecc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_left();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 1));
		ASSERT_EQ('c', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move right in the top row
TEST(GameBoardTest, TestValidRightMoveInTopRow) {
	string gameboardString = "aaeaabbbbbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_right();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::TOP_ROW, 3));
		ASSERT_EQ('a', testBoard.getTileAt(GameBoard::TOP_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move right in the middle row
TEST(GameBoardTest, TestValidRightMoveInMiddleRow) {
	string gameboardString = "aaaaabbbebccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_right();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 4));
		ASSERT_EQ('b', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 3));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player can make a valid move right in the bottom row
TEST(GameBoardTest, TestValidRightMoveInBottomRow) {
	string gameboardString = "aaaaabbbbbccecc";
	GameBoard testBoard(gameboardString);
	try {
		cout << testBoard.get_E_Location();
		testBoard.move_E_right();
		cout << testBoard.get_E_Location();
		testBoard.printCurrentConfiguration();
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 3));
		ASSERT_EQ('c', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 2));
	} catch (IllegalMoveException error) {
		FAIL() << "An exception should NOT have been thrown when moving the empty square";
	}
}

// Test that the player cannot make a valid move up
TEST(GameBoardTest, TestInvalidUpMove) {
	string gameboardString = "aaeaabbbbbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_up();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::TOP_ROW, 2));
	}
}

// Test that the player cannot make a valid move down
TEST(GameBoardTest, TestInvalidDownMove) {
	string gameboardString = "aaaaabbbbbccecc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_down();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 2));
	}
}

// Test that the player cannot make a valid move left in top row
TEST(GameBoardTest, TestInvalidLeftMoveInTopRow) {
	string gameboardString = "eaaaabbbbbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_left();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::TOP_ROW, 0));
	}
}

// Test that the player cannot make a valid move left in middle row
TEST(GameBoardTest, TestInvalidLeftMoveInMiddleRow) {
	string gameboardString = "aaaaaebbbbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_left();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 0));
	}
}

// Test that the player cannot make a valid move left in bottom row
TEST(GameBoardTest, TestInvalidLeftMoveInBottomRow) {
	string gameboardString = "aaaaabbbbbecccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_left();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 0));
	}
}

// Test that the player cannot make a valid move right in top row 
TEST(GameBoardTest, TestInvalidRightMoveInTopRow) {
	string gameboardString = "aaaaebbbbbccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_right();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::TOP_ROW, 4));
	}
}

// Test that the player cannot make a valid move right in top row
TEST(GameBoardTest, TestInvalidRightMoveInMiddleRow) { 
	string gameboardString = "aaaaabbbbeccccc";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_right();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::MIDDLE_ROW, 4));
	}
}

// Test that the player cannot make a valid move right in top row
TEST(GameBoardTest, TestInvalidRightMoveInBottomRow) {
	string gameboardString = "aaaaabbbbbcccce";
	GameBoard testBoard(gameboardString);
	try {
		testBoard.move_E_right();
		FAIL() << "An exception SHOULD have been thrown when moving the empty square";
	} catch (IllegalMoveException error) {
		ASSERT_EQ('e', testBoard.getTileAt(GameBoard::BOTTOM_ROW, 4));
	}
}

// Test that the GameBoard can identify when a board is solved
TEST(GameBoardTest, TestBoardIsSolved) {
	string gameboardString = "aaaaabbbbeaaaaa";
	GameBoard testBoard(gameboardString);
	ASSERT_TRUE(testBoard.isSolved());
}

// Test that the GameBoard can identify when a board is not solved, given that the 'e' is in the top line
TEST(GameBoardTest, TestBoardIsNotSolved_EInTopLine) {
	string gameboardString = "aeaaabbbbbaaaaa";
	GameBoard testBoard(gameboardString);
	ASSERT_FALSE(testBoard.isSolved());
}

// Test that the GameBoard can identify when a board is not solved, given that the 'e' is in the bottom line
TEST(GameBoardTest, TestBoardIsNotSolved_EInBottomLine) {
	string gameboardString = "aaaaabbbbbaaeaa";
	GameBoard testBoard(gameboardString);
	ASSERT_FALSE(testBoard.isSolved());
}

// Test that the GameBoard can identify when a board is not solved, given that the board symbols on top and bottom lines don't match
TEST(GameBoardTest, TestBoardIsNotSolved_LinesDontMatch) {
	string gameboardString = "abbbacceccababa";
	GameBoard testBoard(gameboardString);
	ASSERT_FALSE(testBoard.isSolved());
}

/******************* ALL TESTS FOR LOCATION OF E *******************/

TEST(GameBoardTest, Test_E_At_A) {
	string gameboardString = "errrrrrrrrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('A', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_B) {
	string gameboardString = "rerrrrrrrrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('B', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_C) {
	string gameboardString = "rrerrrrrrrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('C', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_D) {
	string gameboardString = "rrrerrrrrrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('D', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_E) {
	string gameboardString = "rrrrerrrrrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('E', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_F) {
	string gameboardString = "rrrrrerrrrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('F', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_G) {
	string gameboardString = "rrrrrrerrrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('G', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_H) {
	string gameboardString = "rrrrrrrerrrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('H', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_I) {
	string gameboardString = "rrrrrrrrerrrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('I', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_J) {
	string gameboardString = "rrrrrrrrrerrrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('J', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_K) {
	string gameboardString = "rrrrrrrrrrerrrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('K', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_L) {
	string gameboardString = "rrrrrrrrrrrerrr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('L', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_M) {
	string gameboardString = "rrrrrrrrrrrrerr";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('M', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_N) {
	string gameboardString = "rrrrrrrrrrrrrer";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('N', testBoard.get_E_Location());
}

TEST(GameBoardTest, Test_E_At_O) {
	string gameboardString = "rrrrrrrrrrrrrre";
	GameBoard testBoard(gameboardString);
	ASSERT_EQ('O', testBoard.get_E_Location());
}