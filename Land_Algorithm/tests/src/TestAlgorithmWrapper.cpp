//============================================================================
// Name        : TestAlgorithmWrapper.cpp
// Author      : Rubber-Duck-999
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "Land_Algorithm.h"
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
}

int main(int argc, char **argv)
{
    init_log();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
