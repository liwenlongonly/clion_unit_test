#include <iostream>
#include <gtest/gtest.h>

int Add(int a, int b) {
    return a+b;
}

TEST(testCase, test0){
    EXPECT_EQ(14, Add(4, 10));
}

TEST(testCase, test1){
    ASSERT_EQ(6, Add(5, 7));
}

TEST(testCase, test2){
    EXPECT_EQ(28, Add(8, 10)) << "bugs";
}

// 运行参数
class NumberPair {
public:
    NumberPair(int _a, int _b)
    {
        a = _a;
        b = _b;
    }
    int a;
    int b;
};

class FooParamTest : public ::testing::TestWithParam<NumberPair> {

};

INSTANTIATE_TEST_CASE_P(ThreeReturn, FooParamTest, testing::Values(NumberPair(12, 15), NumberPair(18, 21)));

TEST_P(FooParamTest, HandleThreeReturn){
    NumberPair pair = FooParamTest::GetParam();
    EXPECT_EQ(3, Add(pair.a, pair.b));
}

//事件机制
class FooEnvironment : public testing::Environment
{
public:
    virtual void SetUp()
    {
        std::cout << "Foo FooEnvironment SetUP" << std::endl;
    }
    virtual void TearDown()
    {
        std::cout << "Foo FooEnvironment TearDown" << std::endl;
    }
};


class FooCalcTest:public testing::Test
{
protected:
    virtual void SetUp() {
        std::cout << "Foo FooCalcTest SetUP" << std::endl;
    }

    virtual void TearDown() {
        std::cout << "Foo FooCalcTest TearDown" << std::endl;
    }
};

TEST_F(FooCalcTest, HandleNoneZeroInput)
{
    EXPECT_EQ(4, Add(12, 16));
}

TEST_F(FooCalcTest, HandleNoneZeroInput_Error)
{
    EXPECT_EQ(5, Add(12, 16));
}

int main(int argc, char ** argv) {
    std::cout << "Hello, World!" << std::endl;
    testing::AddGlobalTestEnvironment(new FooEnvironment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();  // 执行所有的 test case
}