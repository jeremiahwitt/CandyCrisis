#pragma once
#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "Player.h"
#include "Controller.h"
using namespace std;

/**
 * The AIPlayer is the machine player that will be capable of solving the game without human
 * intervention.
 */
class AIPlayer : public Player {

public:
	AIPlayer() {};
	~AIPlayer() override {};
	void playGame() override;
};
#endif
