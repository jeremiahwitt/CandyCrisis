#pragma once
#include "stdafx.h"
#include "GameBuilder.h"
#include "GameView.h"

GameBuilder::GameBuilder() {
	_playerIsSet = false;
	_configuratorIsSet = false;
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

Controller* GameBuilder::setupGame() {
	if(!_playerIsSet || !_configuratorIsSet) {
		throw 1; 
	}

	string board = _config->getGameBoard();

	// Make sure there's an empty tile!
	if(board.find('e') == string::npos) {
		throw 2; 
	}

	GameBoard* game = new GameBoard(board);
	GameView* view = new GameView(game);
	Controller* gameController = new Controller(game);
	_thePlayer->setController(gameController);

	return gameController;
}
