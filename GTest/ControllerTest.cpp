#include "pch.h"

TEST(ControllerTest, GetSolutionPathUpdated) {
	GameBoard* board = new GameBoard("aaaaabbebbccccc");
	Controller testController(board);

	testController.makeMove(UP);
	testController.makeMove(LEFT);

	string expectedSolutionPathSoFar = "C B ";
	ASSERT_TRUE(expectedSolutionPathSoFar.at(0) == testController.getSolutionPath().at(0));
	ASSERT_TRUE(expectedSolutionPathSoFar.at(2) == testController.getSolutionPath().at(2));

	delete board;
}
