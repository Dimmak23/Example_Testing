#include "../Example.hpp"

#include <gtest/gtest.h>

//name your fixture as your code with tests (I'm not sure if you can change the name)
struct ExampleTests
    : public ::testing::Test
{
    int* x;

    int GetX(){
        return *x;
    }

    virtual void SetUp() override{
        x = new int(42);
    }

    virtual void TearDown() override{
        delete x;
    } 
};

//first field can have name other then a file name
//second field - description of what you are testing
TEST(ExampleTests1, MAC_testing){
    int x = 42;
    int y = 16;
    int sum = 100;
    int oldSum = sum;
    // int expectedNewSum = oldSum + GetX() * y;
    int expectedNewSum = oldSum + x * y;
    EXPECT_EQ(
        expectedNewSum,//we expect that what we test would have this value
        //MAC(GetX(), y, sum)//MAC - name of the testing function
        MAC(x, y, sum)//MAC - name of the testing function
    );
    EXPECT_EQ(
        expectedNewSum,//we expect that what we test would have this value
        sum//sum should changed
    );
}

TEST(ExampleTests2, SQR_Testing){
    int x = 5;
    //int expectedSQR = GetX() * GetX();
    int expectedSQR = x * x;
    EXPECT_EQ(
        expectedSQR,//we expect that what we test would have this value
        //SQR(GetX())//SQR - name of the testing function
        SQR(x)
    );
}