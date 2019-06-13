//============================================================================
// Name        : TestAlgorithmWrapper.cpp
// Author      : Simon Crowther
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "algorithm.h"
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

TEST(Tests, TestAlgoRunFail)
{
    Algorithm algo;
    rocket_simulator::RocketDataParameters rocket_data;
    rocket_simulator::TerrainMissionParameters terrain_data;
    algo.GetRocketDataParameters(rocket_data);
    ASSERT_TRUE(algo.IsRocketSet());
    algo.GetTerrainMissionParameters(terrain_data);
    ASSERT_TRUE(algo.IsWorldSet());
    ASSERT_TRUE(algo.CreateRocketSimulation());
    ASSERT_EQ(algo.algo_data_.size(), 0);
    EXPECT_NE(algo.algo_data_.at(0).velocity_x_, 0.0);
}

TEST(Tests, TestAlgoRunPass)
{
    Algorithm algo;
    //
    rocket_simulator::RocketDataParameters rocket_data;
    rocket_data.mass_ = 80;
    rocket_data.drag_axis_x_ = 0.3;
    rocket_data.drag_axis_y_ = 0.3;
    rocket_data.hori_cross_sect_area_ = 1.0;
    rocket_data.vert_cross_sect_area_ = 1.0;
    rocket_data.thrust_ = 100;
    rocket_data.burn_time_ = 50;
    rocket_data.flow_rate_ = 20;
    rocket_data.angle_of_launch_ = 20;
    //
    rocket_simulator::TerrainMissionParameters terrain_data;
    //
    algo.GetRocketDataParameters(rocket_data);
    ASSERT_TRUE(algo.IsRocketSet());
    terrain_data.density_ = 1.22;
    terrain_data.acceleration_due_to_gravity_ = 9.81;
    algo.GetTerrainMissionParameters(terrain_data);
    ASSERT_TRUE(algo.IsWorldSet());
    ASSERT_TRUE(algo.CreateRocketSimulation());
    ASSERT_GT(algo.algo_data_.size(), 1);
    EXPECT_GT(algo.algo_data_.at(0).velocity_x_, 0.0);
}

int main(int argc, char **argv)
{
    init_log();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
