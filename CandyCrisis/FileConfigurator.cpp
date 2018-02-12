#include "stdafx.h"
#include "FileConfigurator.h"
#include <fstream>
#include <iostream>

/**
 * Public constructor which sets the filepath that'll be used to fetch the gameboard
 */
FileConfigurator::FileConfigurator(string filepath){
	this->_filePath = filepath;
	numGamesPlayed = 0;
}

string FileConfigurator::getFilePath() {
	return this->_filePath;
}

/**
 * This method returns a string containing only the symbols that will set up the board.
 * If there are not the right amount of symbols, or if the file cannot be opened, an
 * exception will be thrown.
 */
string FileConfigurator::getGameBoard() {
	
	// Try to get the file contents. We will try to catch exceptions if any get thrown
	string fileContents;
	try {
		fileContents = _getFileContents();
	} catch (exception err) {
		cout << "Could not get the contents of the file!";
		throw 2;
	}

	if(fileContents.length() < 15) {
		cout << "There aren't enough characters in the file!" << endl;
		throw 3;
	}

	// Get the next 15 characters
	string onlyBoardSymbolsForThisGame;
	try {
		onlyBoardSymbolsForThisGame = fileContents.substr(numGamesPlayed*BOARD_SIZE, BOARD_SIZE);
	} catch (bad_alloc err) {
		cout << "There are not enough symbols in the file to generate another board!";
		throw 2;
	}

	numGamesPlayed++;
	verifyValidBoard(onlyBoardSymbolsForThisGame);
	return onlyBoardSymbolsForThisGame;
}

bool FileConfigurator::hasAnotherBoard() {
	if(numGamesPlayed == 0) {
		return true;
	} else {
		return (_fileContents.size() - (numGamesPlayed * BOARD_SIZE)) >= BOARD_SIZE;
	}
}


/**
 * Returns a string containing what is in the file at the location of _filePath
 */
string FileConfigurator::_getFileContents() {
	if (numGamesPlayed == 0) {
		ifstream gameBoardFile = ifstream(_filePath);
		string line;
		string fileContents;
		if (gameBoardFile.is_open()) {
			while (getline(gameBoardFile, line)) {
				fileContents = fileContents + line + " ";
			}
		} else {
			throw 1;
		}

		_fileContents = _extractBoardSymbolFromFileContents(fileContents);
	}

	return _fileContents;
}

/**
 * Returns a string with ONLY the symbols that represent the board of the game!
 */
string FileConfigurator::_extractBoardSymbolFromFileContents(string fileContents) {
	string onlyBoardSymbols = "";
	for (int i = 0; i < fileContents.length(); i++) {
		if (fileContents.at(i) != ' ') {
			onlyBoardSymbols += fileContents.at(i);
		}
	}

	return onlyBoardSymbols;
}

void FileConfigurator::verifyValidBoard(string boardContents) {
	int countReese = 0;
	int countBazooka = 0;
	int countWalnettos = 0;
	int countYork = 0;
	int countGobstopper = 0;
	int countPez = 0;
	int countEmpty = 0;

	for(int i = 0; i < boardContents.length(); i++) {
		switch(boardContents.at(i)) {
		case 'r':
			countReese++;
			break;
		case 'b':
			countBazooka++;
			break;
		case 'w':
			countWalnettos++;
			break;
		case 'y':
			countYork++;
			break;
		case 'g':
			countGobstopper++;
			break;
		case 'p':
			countPez++;
			break;
		case 'e':
			countEmpty++;
			break;
		}
	}

	if(countEmpty != 1) {
		cout << "I didn't find the right number of empty squares! There should be exactly one!" << endl;
		throw 1;
	}

	// LEVEL 1
	if(countReese == 6 && countBazooka == 6 && countWalnettos == 2) {
		return;
	}

	// LEVEL 2
	if (countReese == 6 && countBazooka == 4 && countWalnettos == 2 && countYork == 2) {
		return;
	}

	// LEVEL 3
	if (countReese == 4 && countBazooka == 4 && countWalnettos == 2 && countYork == 2 && countGobstopper == 2) {
		return;
	}

	// LEVEL 4
	if (countReese == 4 && countBazooka == 2 && countWalnettos == 2 && countYork == 2 && countGobstopper == 2 && countPez == 2) {
		return;
	}

	cout << "The board configuration is invalid!" << endl;
	throw 4;
}
