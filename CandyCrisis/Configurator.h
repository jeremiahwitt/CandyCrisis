#pragma once
#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H
#endif
#include <string>
#include "GameBoard.h"
using namespace std;

/**
 * @class Configurator
 * @brief Abstract class which defines the ability to configure the game board
 */
class Configurator {
public:
	static const int BOARD_SIZE = 15;
	virtual string getGameBoard() = 0;
	Configurator() {};
	virtual ~Configurator() {};
};

