#include "stdafx.h"
#include "FileConfigurator.h"
#include <fstream>
#include <iostream>

/**
 * TODO javadoc
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

	// Get the next 15 characters
	string onlyBoardSymbolsForThisGame;
	try {
		onlyBoardSymbolsForThisGame = fileContents.substr(numGamesPlayed*BOARD_SIZE, BOARD_SIZE);
	} catch (bad_alloc err) {
		cout << "There are not enough symbols in the file to generate another board!";
		throw 2;
	}

	numGamesPlayed++;
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
			throw 1; // TODO maybe change this
		}

		_fileContents = _extractBoardSymbolFromFileContents(fileContents);
	}

	return _fileContents;
}

/**
 * TODO javadoc
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
