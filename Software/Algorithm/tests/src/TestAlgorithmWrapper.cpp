//============================================================================
// Name        : TestAlgorithmWrapper.cpp
// Author      : Simon Crowther
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "Algorithm.h"
#include <gtest/gtest.h>

TEST(SquareRootTest, TestAlgo)
{
	Algorithm algo;
	bool val = algo.createRocketSimulation();
    ASSERT_FALSE(!val);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
