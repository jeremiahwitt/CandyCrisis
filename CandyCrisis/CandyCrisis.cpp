// CandyCrisis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Configurator.h"
#include "FileConfigurator.h"
#include "RandomConfigurator.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "GameView.h"
#include "GameBuilder.h"
#include "GameSetupException.h"
#include "AIPlayer.h"
#include "IllegalMoveException.h"
using namespace std;
using namespace std::chrono;

void showPlayerMenu();
Player* getDesiredPlayerFromInput();

void showLevelMenu();
int getDifficultyLevelFromInput();
void showDifficultyLevelMenu();
Configurator* getDesiredLevelConfiguratorFromInput();

int main() {
	int gameCounter = 0;
	long long durationSum = 0; // TODO remove
	while (true) {
		gameCounter++;
		cout << "Welcome to ~ CANDY CRISIS ~\n";

		// Determine how the level will be generated
		showLevelMenu();
		Configurator* levelConfigurator = getDesiredLevelConfiguratorFromInput();

		// Determine who will be playing the game
		showPlayerMenu();
		Player* player = getDesiredPlayerFromInput();

		// Create blank file for writing results!
		ofstream resultsFile;
		string filename = "results" + to_string(gameCounter) + ".txt";
		resultsFile.open(filename);
		resultsFile.close();

		GameBuilder* builder = new GameBuilder();

		try {
			do {
				milliseconds startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
				Controller* game = builder->player(player)
					->time(startTime)
					->configurator(levelConfigurator)
					->setupGame(gameCounter);

				// Have the player start the game!
				player->playGame();
				durationSum += game->getDuration(); // TODO remove
				delete game;
			} while (levelConfigurator->hasAnotherBoard());
		} catch (GameSetupException err) {
			cout << err.what();
		} catch (IllegalMoveException err) {
			cout << "An illegal move was made, which should not have happened!" << endl;
			system("pause");
			return 0;
		} catch (int e) {
			cout << "There was an issue while running the game! Now terminating!" << endl;
			system("pause");
			return 0;
		}
		cout << "Total time to play was: " << durationSum << endl; // TODO remove
	}
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
Player* getDesiredPlayerFromInput() {
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
		return new HumanPlayer();
	} else {
		cout << "Okay, the AI will play the game then.\n";
		return new AIPlayer();
	}
}

void showLevelMenu() {
	cout << "\nHow would you like to generate the level?\n\n";
	cout << "[1] - Load the level from a file\n";
	cout << "[2] - Generate the level randomly\n";
	cout << "[3] = QUIT\n";
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
		if (menuOption != '1' && menuOption != '2' && menuOption != '3') {
			cout << "\nYou must provide a valid option!\n";
			showDifficultyLevelMenu();
		} else {
			missingInput = false;
		}
	} while (missingInput);

	// 3 - Quit the game!
	if (menuOption == '3') {
		exit(0);
	}

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
		cout << "\nHow many levels do you want to play (enter a number): \n";
		missingInput = true;
		int numLevels;
		string desiredNum;
		do {
			cin >> desiredNum;
			try {
				numLevels = std::stoi(desiredNum);
				missingInput = false;
			} catch(invalid_argument e) {
				cout << "You must provide a number!\n";
			}
		} while (missingInput);
		cout << "Alright, you're going to be playing " << numLevels << " levels.\n";
		desiredConfigurator = new RandomConfigurator(desiredDifficultyLevel, numLevels);
	}

	return desiredConfigurator;
}