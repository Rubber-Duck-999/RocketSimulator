//============================================================================
// Name        : TestInterfaceWrapper.cc
// Author      : Rubber-Duck-999
// Version     :
// Copyright   : Your copyright notice
//============================================================================
#include "interface.h"
#include <gtest/gtest.h>

TEST(Tests, RunConfig)
{
    Interface Controller;
    std::string text = "ID:101-Density:0.0-Gravity:0.0-Mass:0.0-DragX:0.0-DragY:0.0";
    std::string text2 = "-Hori:0.0-Vert:0.0-LaunchAngle:20.0";
    Controller.Receive(text + text2);
    rocket_simulator::StateDataParameters current = Controller.GetCurrentState();
    Controller.Shutdown();
    ASSERT_EQ(current.state_, rocket_simulator::kCONFIGURED);
}

TEST(Tests, RunReady)
{
    Interface Controller;
    std::string text = "ID:101-Density:0.0-Gravity:0.0-Mass:0.0-DragX:0.0-DragY:0.0";
    std::string text2 = "-Hori:0.0-Vert:0.0-LaunchAngle:20.0";
    Controller.Receive(text + text2);
    Controller.Loop();
    rocket_simulator::StateDataParameters current = Controller.GetCurrentState();
    Controller.Shutdown();
    ASSERT_EQ(current.state_, rocket_simulator::kREADY);
}