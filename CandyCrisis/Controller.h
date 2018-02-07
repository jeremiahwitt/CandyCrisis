#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "MovementDirection.h"
#include "GameBoard.h"

class Controller {
public:
	Controller() {};
	virtual bool makeMove(MovementDirection direction) { cout << direction; return true; };
};
#endif