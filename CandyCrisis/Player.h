#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Controller.h"

/**
 * @class Player
 * @Brief Abstract class representing a player, who is capable of playing a Game
 */
class Player {
public:
	virtual ~Player() { delete _gameController;  };
	virtual void playGame() = 0; 
	virtual void setController(Controller* newController) { _gameController = newController; }
protected:
	Controller * _gameController;
};
#endif

