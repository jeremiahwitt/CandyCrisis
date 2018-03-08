#include "pch.h"
#include "../CandyCrisis/AIBoardNode.cpp"
#include <queue>
#include <functional>

using namespace std;

// Tests based on heuristic value
TEST(AIBoardNodeTest, TestZeroHeuristicValue) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111112202211111);

	ASSERT_EQ(0, testNode.heuristicValue());
}

TEST(AIBoardNodeTest, TestOneHeuristicValue) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 112113330311111);

	ASSERT_EQ(1, testNode.heuristicValue());
}

TEST(AIBoardNodeTest, TestTwoHeuristicValue) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 112213330311111);

	ASSERT_EQ(2, testNode.heuristicValue());
}

TEST(AIBoardNodeTest, TestThreeHeuristicValue) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111113303312221);

	ASSERT_EQ(3, testNode.heuristicValue());
}

TEST(AIBoardNodeTest, TestFourHeuristicValue) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111113303322221);

	ASSERT_EQ(4, testNode.heuristicValue());
}

TEST(AIBoardNodeTest, TestFiveHeuristicValue) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 111112202233333);

	ASSERT_EQ(5, testNode.heuristicValue());
}

TEST(AIBoardNodeTest, TestFiveHeuristicValueWithEmptyUpTop) {
	AIBoardNode testNode(nullptr, UP, 1, 2, 110112222233333);

	ASSERT_EQ(5, testNode.heuristicValue());
}

TEST(AIBoardNodeTest, TestPriorityQueue) {
	priority_queue<AIBoardNode*, vector<AIBoardNode*>, CompareNodes>* openList = new priority_queue<AIBoardNode*, vector<AIBoardNode*>, CompareNodes>(); // TODO maybe have to change this to AIBoardNode*
	AIBoardNode testNode1(nullptr, UP, 1, 2, 111113303312221); // 3
	AIBoardNode testNode2(nullptr, UP, 1, 2, 111112202211111); // 0
	AIBoardNode testNode3(nullptr, UP, 1, 2, 111112202211151); // 1
	AIBoardNode testNode4(nullptr, UP, 1, 2, 112213330311111); // 2

	openList->push(&testNode1);
	openList->push(&testNode2);
	openList->push(&testNode3);
	openList->push(&testNode4);

	ASSERT_EQ(4, openList->size());
	ASSERT_EQ(3, testNode1.heuristicValue());
	ASSERT_EQ(0, testNode2.heuristicValue());
	ASSERT_EQ(1, testNode3.heuristicValue());
	ASSERT_EQ(2, testNode4.heuristicValue());


	ASSERT_EQ(111112202211111, openList->top()->getBoardState());
	openList->pop();
	ASSERT_EQ(111112202211151, openList->top()->getBoardState());
	openList->pop();
	ASSERT_EQ(112213330311111, openList->top()->getBoardState());
	openList->pop();
	ASSERT_EQ(111113303312221, openList->top()->getBoardState());
	openList->pop();

	delete openList;
}

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