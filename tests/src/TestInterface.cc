//============================================================================
// Name        : TestControllerWrapper.cpp
// Author      : Rubber-Duck-999
// Version     :
// Copyright   : Your copyright notice
//============================================================================
#include "logging.h"
#include <gtest/gtest.h>

TEST(Tests, ID)
{
    int x = 0;
    ASSERT_EQ(x, 0);
}

int main(int argc, char **argv)
{
    init_log();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
