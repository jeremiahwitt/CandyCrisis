#pragma once
#ifndef PLAYER_H
#define PLAYER_H

/**
 * @class Player
 * @Brief Abstract class representing a player, who is capable of playing a Game
 */
class Player {
public:
	virtual ~Player() = default;
	virtual void playGame() = 0; //TODO make this take an argument, which is the controller!
	
};
#endif

