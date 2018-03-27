#pragma once
#ifndef RANDOMCONFIGURATOR_H
#define RANDOMCONFIGURATOR_H
#include "Configurator.h"
#include <vector>
using namespace std;

class RandomConfigurator : public Configurator {
public:
	RandomConfigurator(int difficultyLevel);
	RandomConfigurator(int difficultyLevel, int numLevels);
	virtual string getGameBoard();
	virtual bool hasAnotherBoard() {
		return _numLevels > 0;
	}
	virtual int recentDifficulty() { return _difficultyLevel; }
private:
	int _numLevels;
	int _difficultyLevel;
	vector<char> _getCharsForLevel();
};
#endif