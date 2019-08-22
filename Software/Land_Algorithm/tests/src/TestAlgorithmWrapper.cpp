//============================================================================
// Name        : TestAlgorithmWrapper.cpp
// Author      : Simon Crowther
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "land_algorithm.h"
#include <gtest/gtest.h>


void CreateMap(std::map<unsigned int, double>& map, double value)
{
    for(unsigned int i = 0; i < 10000; i++)
    {
        map.insert(std::pair<unsigned int, double>(i, value));
    }
}

void CreateAlgo(std::vector<rocket_simulator::AlgoData>& algo_data)
{
    for(int i = 0; i < 4000; i++)
    {
        rocket_simulator::AlgoData data(i, 101, 90.0, i);
        algo_data.push_back(data);
    }
    for(int i = 4000; i < 4010; i++)
    {
        rocket_simulator::AlgoData data(i, 99, 90.0, i);
        algo_data.push_back(data);
    }
}


TEST(Tests, TestAlgoFail)
{
    Land_Algorithm algo;
    bool result = algo.RunAlgorithm();
    ASSERT_FALSE(result);
}

TEST(Tests, TestAlgoFailWithMap)
{
    std::map<unsigned int, double> map;
    Land_Algorithm algo;
    CreateMap(map, 100.0);
    algo.Set2DMap(map);
    bool result = algo.RunAlgorithm();
    ASSERT_FALSE(result);
}

TEST(Tests, TestAlgoPass)
{
    std::map<unsigned int, double> map;
    std::vector<rocket_simulator::AlgoData> algo_data;
    Land_Algorithm algo;
    CreateMap(map, 100.0);
    CreateAlgo(algo_data);
    algo.Set2DMap(map);
    algo.SetRocketAlgoData(algo_data);
    bool result = algo.RunAlgorithm();
    ASSERT_TRUE(result);
    ASSERT_TRUE(algo.DidTheRocketCrash());
}

TEST(Tests, TestAlgoPassRocketSite)
{
    std::map<unsigned int, double> map;
    std::vector<rocket_simulator::AlgoData> algo_data;
    Land_Algorithm algo;
    CreateMap(map, 100.0);
    CreateAlgo(algo_data);
    algo.Set2DMap(map);
    algo.SetRocketAlgoData(algo_data);
    bool result = algo.RunAlgorithm();
    ASSERT_TRUE(result);
    ASSERT_TRUE(algo.DidTheRocketCrash());
    ASSERT_EQ(algo.GetXAxisLandingPoint(),4000);
    ASSERT_DOUBLE_EQ(algo.GetYAxisLandingPoint(),100.0);
}

int main(int argc, char **argv)
{
    init_log();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
