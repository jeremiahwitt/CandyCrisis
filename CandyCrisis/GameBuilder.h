#pragma once
#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H
#include <chrono>
#include "Player.h"
#include "Configurator.h"
#include "Controller.h"
using namespace std::chrono;

class GameBuilder {
public:
	GameBuilder();
	GameBuilder* time(milliseconds startTime);
	GameBuilder* player(Player* thePlayer);
	GameBuilder* configurator(Configurator* theConfig);
	Controller* setupGame(int gameNumber);
private:
	bool _playerIsSet;
	bool _configuratorIsSet;
	Player* _thePlayer;
	Configurator* _config;
	milliseconds _startTime;
};
#endif
