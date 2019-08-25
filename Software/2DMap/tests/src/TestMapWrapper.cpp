//============================================================================
// Name        : TestMapWrapper.cpp
// Author      : Rubber-Duck-999
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include "map.h"
#include <gtest/gtest.h>

TEST(Tests, TestMapSizePass)
{
    int size = 1000;
    Map map(-50.0, 255.0, size);
    map.CreateInitialMap();
    std::map<unsigned int, double> my_map;
    map.GetMap(my_map);
    ASSERT_EQ(my_map.size(), size);
}

TEST(Tests, TestMapSizeMax)
{
    Map map(-50.0, 255.0, 10);
    map.SetMaxSize(10000);
    map.CreateInitialMap();
    std::map<unsigned int, double> my_map;
    map.GetMap(my_map);
    ASSERT_EQ(my_map.size(), 10000);
}

TEST(Tests, TestMapRange)
{
    int size = 5000;
    Map map(-50.0, 255.0, size);
    map.CreateInitialMap();
    std::map<unsigned int, double> my_map;
    map.GetMap(my_map);
    ASSERT_GT(my_map.at(size - 1), -50.0);
    ASSERT_LT(my_map.at(size - 1), 255.0);
}


int main(int argc, char **argv)
{
    init_log();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
