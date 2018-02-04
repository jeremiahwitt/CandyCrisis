#include "pch.h"
#include "../CandyCrisis/RandomConfigurator.cpp"


/**
* Counts the number of occurences of the desired char.
* @param gameboard - the gameboard to be checked
* @param c - the char to be counter
* @return int
*/
int countChar(string gameboard, char c) {
	int counter = 0;
	for (int i = 0; i < gameboard.size(); i++) {
		if (gameboard.at(i) == c) {
			counter++;
		}
	}

	return counter;
}

/**
* Counts the number of occurences of 'r' in the gameboard
* @param gameboard - the gameboard to be checked
* @return int
*/
int countReese(string gameboard) {
	return countChar(gameboard, 'r');
}

/**
* Counts the number of occurences of 'b' in the gameboard
* @param gameboard - the gameboard to be checked
* @return int
*/
int countBazooka(string gameboard) {
	return countChar(gameboard, 'b');
}

/**
* Counts the number of occurences of 'w' in the gameboard
* @param gameboard - the gameboard to be checked
* @return int
*/
int countWalnetto(string gameboard) {
	return countChar(gameboard, 'w');
}

/**
* Counts the number of occurences of 'y' in the gameboard
* @param gameboard - the gameboard to be checked
* @return int
*/
int countYork(string gameboard) {
	return countChar(gameboard, 'y');
}

/**
* Counts the number of occurences of 'g' in the gameboard
* @param gameboard - the gameboard to be checked
* @return int
*/
int countGobstopper(string gameboard) {
	return countChar(gameboard, 'g');
}

/**
* Counts the number of occurences of 'p' in the gameboard
* @param gameboard - the gameboard to be checked
* @return int
*/
int countPez(string gameboard) {
	return countChar(gameboard, 'p');
}

TEST(RandomConfiguratorTests, TestLevel1) {
	RandomConfigurator testConfigurator(1);
	string gameBoard = testConfigurator.getGameBoard();
	ASSERT_EQ(6, countReese(gameBoard));
	ASSERT_EQ(6, countBazooka(gameBoard));
	ASSERT_EQ(2, countWalnetto(gameBoard));
	ASSERT_FALSE(gameBoard.find('e') == string::npos); // Assert that 'e' can be found
}

TEST(RandomConfiguratorTests, TestLevel2) {
	RandomConfigurator testConfigurator(2);
	string gameBoard = testConfigurator.getGameBoard();
	ASSERT_EQ(6, countReese(gameBoard));
	ASSERT_EQ(4, countBazooka(gameBoard));
	ASSERT_EQ(2, countWalnetto(gameBoard));
	ASSERT_EQ(2, countYork(gameBoard));
	ASSERT_FALSE(gameBoard.find('e') == string::npos); // Assert that 'e' can be found
}

TEST(RandomConfiguratorTests, TestLevel3) {
	RandomConfigurator testConfigurator(3);
	string gameBoard = testConfigurator.getGameBoard();
	ASSERT_EQ(4, countReese(gameBoard));
	ASSERT_EQ(4, countBazooka(gameBoard));
	ASSERT_EQ(2, countWalnetto(gameBoard));
	ASSERT_EQ(2, countYork(gameBoard));
	ASSERT_EQ(2, countGobstopper(gameBoard));
	ASSERT_FALSE(gameBoard.find('e') == string::npos); // Assert that 'e' can be found1
}

TEST(RandomConfiguratorTests, TestLevel4) {
	RandomConfigurator testConfigurator(4);
	string gameBoard = testConfigurator.getGameBoard();
	ASSERT_EQ(4, countReese(gameBoard));
	ASSERT_EQ(2, countBazooka(gameBoard));
	ASSERT_EQ(2, countWalnetto(gameBoard));
	ASSERT_EQ(2, countYork(gameBoard));
	ASSERT_EQ(2, countGobstopper(gameBoard));
	ASSERT_EQ(2, countPez(gameBoard));
	ASSERT_FALSE(gameBoard.find('e') == string::npos); // Assert that 'e' can be found1
}