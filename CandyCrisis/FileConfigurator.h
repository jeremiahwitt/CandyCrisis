#pragma once
#ifndef FILECONFIGURATOR_H
#define FILECONFIGURATOR_H
#include <fstream>
#include <string>
using namespace std;
#include "Configurator.h"

/**
 * @class FileConfigurator
 * @brief Will retrieve level information from a file in order to configure the
 * game board.
 */
class FileConfigurator : public Configurator {
public:
	FileConfigurator(string filepath);
	string getFilePath();
	virtual string getGameBoard() override;
private:
	string _filePath;
	string _getFileContents();
	string _extractBoardSymbolFromFileContents(string fileContents);

};
#endif
