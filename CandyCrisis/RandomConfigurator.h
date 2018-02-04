#pragma once
#ifndef RANDOMCONFIGURATOR_H
#define RANDOMCONFIGURATOR_H
#include "Configurator.h"

class RandomConfigurator : public Configurator {
public:
	RandomConfigurator(int difficultyLevel);
	virtual string getGameBoard();
private:
	int _difficultyLevel;
	vector<char> _getCharsForLevel();
};
#endif