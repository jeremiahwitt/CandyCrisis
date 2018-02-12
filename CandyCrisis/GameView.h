#pragma once
#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "Observer.h"
#include "GameBoard.h"


class GameView : Observer {
public:
	GameView(GameBoard* board) { _board = board; _board->attach(this); };
	void update() { _board->printCurrentConfiguration(); };
	~GameView() { if (_board != nullptr) { _board->detach(this); } }
private:
	GameBoard* _board;
};
#endif