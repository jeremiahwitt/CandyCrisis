#include "pch.h"
#include "../CandyCrisis/FileConfigurator.cpp"

static const string testFilePath = "testGameBoard.txt";

void _writeTestFile(string fileContents) {
	ofstream testFile;
	testFile.open(testFilePath);
	testFile << fileContents;
	testFile.close();
}

// Tests that the path of the FileConfigurator gets set properly
TEST(FileConfiguratorTests, TestGetFilePath) {
	string filePath = "testPath";
	FileConfigurator test(filePath);
	EXPECT_EQ(filePath, test.getFilePath());
}

// Test that an exception gets thrown if the file does not exist
TEST(FileConfiguratorTests, TestGetGameBoard_FileDoesntExist) {
	string filePath = "doesntExist";
	FileConfigurator test(filePath);
	try {
		test.getGameBoard();
	} catch (int err) {
		EXPECT_EQ(err, 1);
	} catch(...) {
		FAIL() << "Did not receive the expected exception!";
	}
}

// Test that the game board contents get returned properly if the file does exist and is proper
TEST(FileConfiguratorTests, TestGetGameBoard_FileDoesExist) {
	string testFileContents = "A B C D E F T A J K T L K J A";
	
	// Write the test file contents to the test file, and set up the FileConfigurator
	_writeTestFile(testFileContents);
	FileConfigurator test(testFilePath);
	string gameBoardContents;
	try {
		gameBoardContents = test.getGameBoard();
	} catch (int err) {
		remove(testFilePath.c_str());
		FAIL() << "An exception should not have been thrown!";
	} 
	ASSERT_EQ("ABCDEFTAJKTLKJA", gameBoardContents);
	remove(testFilePath.c_str());
}

TEST(FileConfiguratorTests, TestExceptionIfNotEnoughCharacters) {
	// Will write only 14 characters to the file
	string testFileContents = "1 2 3 4 5 6 7 8 9 0 a b c d";

	_writeTestFile(testFileContents);
	FileConfigurator test(testFilePath);
	try {
		test.getGameBoard();
		remove(testFilePath.c_str());
		FAIL() << "An exception should have been thrown, because the file is too short!";
	} catch (int err) {
		remove(testFilePath.c_str());
		ASSERT_EQ(2, err);
	}
}

TEST(FileConfiguratorTests, TestExceptionIfTooManyCharacters) {
	// Will write only 14 characters to the file
	string testFileContents = "1 2 3 4 5 6 7 8 9 0 a b c d e f";

	_writeTestFile(testFileContents);
	FileConfigurator test(testFilePath);
	try {
		test.getGameBoard();
		remove(testFilePath.c_str());
		FAIL() << "An exception should have been thrown, because the file is too long!";
	} catch (int err) {
		remove(testFilePath.c_str());
		ASSERT_EQ(2, err);
	}
}




