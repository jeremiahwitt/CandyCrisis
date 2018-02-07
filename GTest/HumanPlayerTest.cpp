#include "pch.h"
#include "../CandyCrisis/Controller.h"
#include "../CandyCrisis/HumanPlayer.cpp"
#include <thread>
#include <windows.h>

void makeUpMove();

TEST(HumanPlayerTests, MakeUpMove) {
	Controller* myController = new Controller();
	HumanPlayer testPlayer(myController);

	//thread move(makeUpMove);
	testPlayer.playGame();
	//thread move(quit);
	// Validate that the e moved up
	system("pause");

};

// Make test to make sure the e moves down
// make test to make sure the e moves left
// make test to make sure the e moves right
// Make test that an invalid move throws an exception
void makeUpMove() {
	testing::internal::SleepMilliseconds(1000);
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	input.ki.wVk = 0x57;
	input.ki.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));

}