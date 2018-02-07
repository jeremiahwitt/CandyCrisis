#pragma once
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include "Controller.h"
using namespace std;

class HumanPlayer : Player {

public:
	HumanPlayer(Controller* gameController);
	~HumanPlayer() override {};
	void playGame() override;
private:
	Controller* _gameController;
	static void displayValidKeys();
};
#endif
