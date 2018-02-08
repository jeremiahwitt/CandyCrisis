#include "stdafx.h"
#include "FileConfigurator.h"
#include <fstream>
#include <iostream>

/**
 * TODO javadoc
 */
FileConfigurator::FileConfigurator(string filepath){
	this->_filePath = filepath;
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
	string fileContents = _getFileContents();
	string onlyBoardSymbols = _extractBoardSymbolFromFileContents(fileContents);
	cout << onlyBoardSymbols;

	if(onlyBoardSymbols.length() != BOARD_SIZE) {
		throw 2; // TODO give better exception
	}

	return onlyBoardSymbols;
}

/**
 * Returns a string containing what is in the file at the location of _filePath
 */
string FileConfigurator::_getFileContents() {
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

	return fileContents;
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
