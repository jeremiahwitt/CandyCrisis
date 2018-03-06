#include "pch.h"
#include "../CandyCrisis/AIBoardNode.cpp"


using namespace std;

// Tests based on validation of movement direction
TEST(AIBoardNodeTest, TestCanMoveUp_Valid) {
	AIBoardNode testNode(nullptr, UP, 1, 1, 5);
	ASSERT_TRUE(testNode.canMove(UP));
}

TEST(AIBoardNodeTest, TestCanMoveUp_Invalid) {
	AIBoardNode testNode(nullptr, UP, 0, 1, 5);
	ASSERT_FALSE(testNode.canMove(UP));
}

TEST(AIBoardNodeTest, TestCanMoveDown_Valid) {
	AIBoardNode testNode(nullptr, UP, 0, 1, 5);
	ASSERT_TRUE(testNode.canMove(DOWN));
}

TEST(AIBoardNodeTest, TestCanMoveDown_Invalid) {
	AIBoardNode testNode(nullptr, UP, 2, 1, 5);
	ASSERT_FALSE(testNode.canMove(DOWN));
}

TEST(AIBoardNodeTest, TestCanMoveLeft_Valid) {
	AIBoardNode testNode(nullptr, UP, 2, 1, 5);
	ASSERT_TRUE(testNode.canMove(LEFT));
}

TEST(AIBoardNodeTest, TestCanMoveLeft_InValid) {
	AIBoardNode testNode(nullptr, UP, 2, 0, 5);
	ASSERT_FALSE(testNode.canMove(LEFT));
}

TEST(AIBoardNodeTest, TestCanMoveRight_Valid) {
	AIBoardNode testNode(nullptr, UP, 2, 0, 5);
	ASSERT_TRUE(testNode.canMove(RIGHT));
}

TEST(AIBoardNodeTest, TestCanMoveRight_InValid) {
	AIBoardNode testNode(nullptr, UP, 2, 4, 5);
	ASSERT_FALSE(testNode.canMove(RIGHT));
}

// Tests for the generation of children nodes
TEST(AIBoardNodeTest, TestGenerateUpChild) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111112202233333);

	AIBoardNode* childNode = testNode.generateChildFromMovement(UP);
	// Test that the parent is set properly
	ASSERT_EQ(&testNode, childNode->getParent());

	// Test that the e location changed properly 
	ASSERT_EQ(0, childNode->get_E_VerticalPosition());
	ASSERT_EQ(2, childNode->get_E_HorizontalPosition());

	// Test that the movement direction is set properly
	ASSERT_EQ(UP, childNode->getMovementGeneratedBy());

	// Test that the key is proper
	ASSERT_EQ(110112212233333, childNode->getBoardState());

}

TEST(AIBoardNodeTest, TestGenerateDownChild) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111112202233333);

	AIBoardNode* childNode = testNode.generateChildFromMovement(DOWN);
	// Test that the parent is set properly
	ASSERT_EQ(&testNode, childNode->getParent());

	// Test that the e location changed properly 
	ASSERT_EQ(2, childNode->get_E_VerticalPosition());
	ASSERT_EQ(2, childNode->get_E_HorizontalPosition());

	// Test that the movement direction is set properly
	ASSERT_EQ(DOWN, childNode->getMovementGeneratedBy());

	// Test that the key is proper
	ASSERT_EQ(111112232233033, childNode->getBoardState());
}

TEST(AIBoardNodeTest, TestGenerateLeftChild) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111112202233333);

	AIBoardNode* childNode = testNode.generateChildFromMovement(LEFT);
	// Test that the parent is set properly
	ASSERT_EQ(&testNode, childNode->getParent());

	// Test that the e location changed properly 
	ASSERT_EQ(1, childNode->get_E_VerticalPosition());
	ASSERT_EQ(1, childNode->get_E_HorizontalPosition());

	// Test that the movement direction is set properly
	ASSERT_EQ(LEFT, childNode->getMovementGeneratedBy());

	// Test that the key is proper
	ASSERT_EQ(111112022233333, childNode->getBoardState());
}

TEST(AIBoardNodeTest, TestGenerateRightChild) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111112202233333);

	AIBoardNode* childNode = testNode.generateChildFromMovement(RIGHT);
	// Test that the parent is set properly
	ASSERT_EQ(&testNode, childNode->getParent());

	// Test that the e location changed properly 
	ASSERT_EQ(1, childNode->get_E_VerticalPosition());
	ASSERT_EQ(3, childNode->get_E_HorizontalPosition());

	// Test that the movement direction is set properly
	ASSERT_EQ(RIGHT, childNode->getMovementGeneratedBy());

	// Test that the key is proper
	ASSERT_EQ(111112220233333, childNode->getBoardState());

}