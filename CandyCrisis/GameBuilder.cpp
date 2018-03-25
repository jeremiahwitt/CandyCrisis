#include "stdafx.h"
#pragma once
#include "GameBuilder.h"
#include "GameView.h"
#include "HumanPlayer.h"

GameBuilder::GameBuilder() {
	_playerIsSet = false;
	_configuratorIsSet = false;
}

/**
 * Will be used to provide the configurator with the time when the game creation process
 * started
 */
GameBuilder* GameBuilder::time(milliseconds startTime) {
	_startTime = startTime;
	return this;
}

/**
 * Sets the Player to be used by the GameBuilder
 */
GameBuilder* GameBuilder::player(Player* thePlayer) {
	_thePlayer = thePlayer;
	_playerIsSet = true;
	return this;
}

/**
 * Sets the Configurator to be used by the GameBuilder when getting a game ready
 */
GameBuilder* GameBuilder::configurator(Configurator* theConfig) {
	_config = theConfig;
	_configuratorIsSet = true;
	return this;
}

Controller* GameBuilder::setupGame(int gameNumber) {
	if(!_playerIsSet || !_configuratorIsSet) {
		throw 1; 
	}

	string board = _config->getGameBoard();

	// Make sure there's an empty tile!
	if(board.find('e') == string::npos) {
		throw 2; 
	}

	GameBoard* game = new GameBoard(board);
	Controller* gameController = new Controller(game, _startTime);
	gameController->setGameNumber(gameNumber);
	_thePlayer->setController(gameController);
	if(dynamic_cast<HumanPlayer*>(_thePlayer)) {
		gameController->setIsHuman(true);
		GameView* view = new GameView(game);
		game->printCurrentConfiguration();
	} else {
		gameController->setIsHuman(false);
	}

	return gameController;
}
