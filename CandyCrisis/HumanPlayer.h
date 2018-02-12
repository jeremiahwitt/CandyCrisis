#pragma once
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include "Controller.h"
using namespace std;

class HumanPlayer : public Player {

public:
	HumanPlayer() {};
	~HumanPlayer() override {};
	void playGame() override;
private:
	static void displayValidKeys();
};
#endif
