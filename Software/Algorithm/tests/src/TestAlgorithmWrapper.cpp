//============================================================================
// Name        : TestAlgorithmWrapper.cpp
// Author      : Simon Crowther
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "Algorithm.h"
#include <gtest/gtest.h>

TEST(Tests, TestAlgoRocket)
{
    Algorithm algo;
    rocket_simulator::RocketDataParameters rocket_data;
    algo.GetRocketDataParameters(rocket_data);
    ASSERT_TRUE(algo.IsRocketSet());
    ASSERT_FALSE(algo.CreateRocketSimulation());
}

TEST(Tests, TestAlgoBoth)
{
    Algorithm algo;
    rocket_simulator::RocketDataParameters rocket_data;
    rocket_simulator::TerrainMissionParameters terrain_data;
    algo.GetRocketDataParameters(rocket_data);
    ASSERT_TRUE(algo.IsRocketSet());
    algo.GetTerrainMissionParameters(terrain_data);
    ASSERT_TRUE(algo.IsWorldSet());
    ASSERT_TRUE(algo.CreateRocketSimulation());
}



int main(int argc, char **argv)
{
    init_log();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
