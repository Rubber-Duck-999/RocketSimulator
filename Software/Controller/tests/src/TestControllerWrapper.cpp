//============================================================================
// Name        : TestControllerWrapper.cpp
// Author      : Simon Crowther
// Version     :
// Copyright   : Your copyright notice
//============================================================================
#include "interface.h"
#include <gtest/gtest.h>

TEST(Tests, Initiate)
{
    Interface Controller;
    Controller.Receive();
    rocket_simulator::StateDataParameters current = Controller.GetCurrentState();
    ASSERT_EQ(current.state, rocket_simulator::kREADY);    
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
