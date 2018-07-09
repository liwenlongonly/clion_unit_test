#include <iostream>
#include <gtest/gtest.h>

int Add(int a, int b)
{
    return a+b;
}

TEST(testCase, test0)
{
    EXPECT_EQ(14, Add(4, 10));
}

TEST(testCase, test1)
{
    EXPECT_EQ(6, Add(5, 7));
}

TEST(testCase, test2)
{
    EXPECT_EQ(28, Add(8, 10)) << "bugs";
}

int main(int argc, char ** argv) {
    std::cout << "Hello, World!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}