// CandyCrisis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Configurator.h"
#include "FileConfigurator.h"
#include "RandomConfigurator.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "GameView.h"
#include "GameBuilder.h"
#include "GameSetupException.h"
// #include "Configurator.h"
// #include "FileConfigurator.h"
using namespace std;

/**
 * Simple enum used to indicate if the player of the game is Human or an AI
 */
enum PlayerEnum {
	AI,
	Human
};

void showPlayerMenu();
PlayerEnum getDesiredPlayerFromInput();

void showLevelMenu();
int getDifficultyLevelFromInput();
void showDifficultyLevelMenu();
Configurator* getDesiredLevelConfiguratorFromInput();

int main() {

	cout << "Welcome to ~ CANDY CRISIS ~\n";
	
	// Determine how the level will be generated
	showLevelMenu();
	Configurator* levelConfigurator = getDesiredLevelConfiguratorFromInput();

	/* The following section will be implemented once an AI player is used in the game
	// Determine who will be playing the game
	showPlayerMenu();
	desiredPlayer = getDesiredPlayerFromInput(); */
	Player* player = new HumanPlayer();

	GameBuilder* builder = new GameBuilder();

	try {
		do {
			Controller* game = builder->player(player)
								->configurator(levelConfigurator)
								->setupGame();
			player->playGame();
			delete game;
		} while (levelConfigurator->hasAnotherBoard());
	} catch (GameSetupException err) {
		cout << err.what();
	} catch (int e) {
		cout << "There was an issue while running the game! Now terminating!" << endl;
	}

	system("pause");
    return 0;
}


/**
* Displays to the user the menu that provides input options for who will play the game.
*/
void showPlayerMenu() {
	cout << "\nWho will be playing the game?\n\n";
	cout << "[1] - Play the game myself\n";
	cout << "[2] - Have the AI play the game\n";
	cout << "\nPress the number corresponding to the option you want, followed by ENTER\n";
}


/**
* Gets input from the user indicating who will be playing the game.
* 1 = Human
* 2 = AI
*/
PlayerEnum getDesiredPlayerFromInput() {
	bool missingInput = true;
	char menuOption;
	do {
		cin >> menuOption;
		if (menuOption != '1' && menuOption != '2') {
			cout << "\nYou must provide a valid option!\n";
			showPlayerMenu();
		} else {
			missingInput = false;
		}
	} while (missingInput);

	if (menuOption == '1') {
		cout << "Alright, you will be playing the game!\n";
		return Human;
	} else {
		cout << "Okay, the AI will play the game then.\n";
		return AI;
	}
}

void showLevelMenu() {
	cout << "\nHow would you like to generate the level?\n\n";
	cout << "[1] - Load the level from a file\n";
	cout << "[2] - Generate the level randomly\n";
	cout << "\nPress the number corresponding to the option you want, followed by ENTER\n";
}

int getDifficultyLevelFromInput() {
	bool missingInput = true;
	char menuOption;

	do {
		cin >> menuOption;
		if (menuOption < '1' || menuOption > '5') {
			cout << "\nYou must provide a valid option!\n";
			showLevelMenu();
		} else {
			missingInput = false;
		}
	} while (missingInput);

	return menuOption - '0'; // convert it back to an int, with 0 acting as the offset
}

void showDifficultyLevelMenu() {
	cout << "\nPlease indicate the level of difficulty you'd like to have:\n";
	cout << "[1] - Novice\n";
	cout << "[2] - Apprentice\n";
	cout << "[3] - Expert\n";
	cout << "[4] - Master\n";
}


/**
* Can be used to get a Configurator based on the users input, which will configure the
* GameBoard accordingly!
*/
Configurator* getDesiredLevelConfiguratorFromInput() {
	Configurator* desiredConfigurator;
	bool missingInput = true;
	char menuOption;

	// Get the menu option that the user wants to use (either 1 or 2)
	do {
		cin >> menuOption;
		if (menuOption != '1' && menuOption != '2') {
			cout << "\nYou must provide a valid option!\n";
			showDifficultyLevelMenu();
		} else {
			missingInput = false;
		}
	} while (missingInput);

	// 1 - Level will be loaded from file
	if (menuOption == '1') {
		cout << "\nPlease enter the location of the file you'd like to load:\n";
		string filePath;
		cin >> filePath;
		desiredConfigurator = new FileConfigurator(filePath); 
		return desiredConfigurator;

		// 2 - Random level
	} else {
		showDifficultyLevelMenu();
		int desiredDifficultyLevel = getDifficultyLevelFromInput();
		cout << "Alright, you're going to be playing difficulty level " << desiredDifficultyLevel << "\n";
		desiredConfigurator = new RandomConfigurator(desiredDifficultyLevel);
	}

	return desiredConfigurator;
}