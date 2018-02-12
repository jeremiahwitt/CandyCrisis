#pragma once
#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H
#include "Player.h"
#include "Configurator.h"
#include "Controller.h"

class GameBuilder {
public:
	GameBuilder();
	GameBuilder* player(Player* thePlayer);
	GameBuilder* configurator(Configurator* theConfig);
	Controller* setupGame();
private:
	bool _playerIsSet;
	bool _configuratorIsSet;
	Player* _thePlayer;
	Configurator* _config;
};
#endif
