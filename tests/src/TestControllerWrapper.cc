//============================================================================
// Name        : TestControllerWrapper.cpp
// Author      : Rubber-Duck-999
// Version     :
// Copyright   : Your copyright notice
//============================================================================
#include "logging.h"
#include "interface.h"
#include <gtest/gtest.h>

TEST(Tests, ID)
{
    Interface Controller;
    Controller.Receive("ID:101");
    Controller.Shutdown();
    ASSERT_EQ(Controller.GetIdNumber(), 102);    
}


TEST(Tests, Initiate)
{
    Interface Controller;
    Controller.Receive("");
    rocket_simulator::StateDataParameters current = Controller.GetCurrentState();
    Controller.Shutdown();
    ASSERT_NE(current.state_, rocket_simulator::kREADY);    
}

TEST(Tests, GetStateLaunch)
{
    Interface Controller;
    Controller.Receive("ID:101");
    rocket_simulator::StateDataParameters current = Controller.GetCurrentState();
    Controller.Shutdown();
    ASSERT_NE(current.state_, rocket_simulator::kLAUNCH);
}

TEST(Tests, RunAlgoPartialFail)
{
    Interface Controller;
    Controller.Receive("ID:101-Density:0.0-Gravity:0.0-Mass:0.0-DragX:0.0");
    rocket_simulator::StateDataParameters current = Controller.GetCurrentState();
    Controller.Shutdown();
    ASSERT_EQ(current.state_, rocket_simulator::kNON_CONFIGURED);
}


int main(int argc, char **argv)
{
    init_log();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
