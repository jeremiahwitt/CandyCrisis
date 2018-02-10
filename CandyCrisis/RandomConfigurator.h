#pragma once
#ifndef RANDOMCONFIGURATOR_H
#define RANDOMCONFIGURATOR_H
#include "Configurator.h"
#include <vector>
using namespace std;

class RandomConfigurator : public Configurator {
public:
	RandomConfigurator(int difficultyLevel);
	virtual string getGameBoard();
	virtual bool hasAnotherBoard() {
		return false;
	}
private:
	int _difficultyLevel;
	vector<char> _getCharsForLevel();
};
#endif