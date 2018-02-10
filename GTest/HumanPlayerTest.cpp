#include "pch.h"
#include <thread>
#include <windows.h>
#include "../CandyCrisis/HumanPlayer.cpp"
#include "../CandyCrisis/Controller.cpp"


void makeUpMove();
void exitGame();
void simulateKeyPress(int keycode);

TEST(HumanPlayerTests, MakeUpMove) {
	GameBoard* board = new GameBoard("aaaaabbebbccccc");
	Controller* myController = new Controller(board);
	HumanPlayer testPlayer(myController);

	thread move(makeUpMove);

	testPlayer.playGame();
	move.join();

	ASSERT_EQ('C', board->get_E_Location());
};

// Make test to make sure the e moves down
// make test to make sure the e moves left
// make test to make sure the e moves right
// Make test that an invalid move throws an exception
void makeUpMove() {
	testing::internal::SleepMilliseconds(400);
	simulateKeyPress(0x57); // W
	exitGame();
	exitGame();
}

void exitGame() {
	testing::internal::SleepMilliseconds(100);
	simulateKeyPress(0x45); // W
}

void simulateKeyPress(int keycode) {
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	input.ki.wVk = keycode;
	input.ki.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}
