#include "pch.h"
#include "../CandyCrisis/AIPlayerUtilities.cpp"


using namespace std;

TEST(AIPlayerTest, TestGenerateNumericalBoard) {
	string gameboardString = "rbwygprrerbwygp";
	long long int val = AIPlayerUtilities::generateNumericalBoard(gameboardString);
	ASSERT_EQ(123456110123456, val);
}