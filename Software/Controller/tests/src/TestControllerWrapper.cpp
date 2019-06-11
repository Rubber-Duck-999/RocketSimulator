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
    ASSERT_TRUE(true);    
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
