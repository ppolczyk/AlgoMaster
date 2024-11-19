#include "../include/vector.h"
#include <gtest/gtest.h>

class VectorTestFixture : public ::testing::Test {
protected:
    // This method runs before each test in the fixture
    // void SetUp() override {
    //}

    // This method runs after each test in the fixture (optional)
    //    void TearDown() override {
    //}

    Vector<int> vec;
};

TEST_F(VectorTestFixture, vectorPushBackAndSizeTest) {
    EXPECT_EQ(vec.size(),0);

    vec.push_back(1);
    EXPECT_EQ(vec.size(),1);
    EXPECT_EQ(vec[0],1);

    vec.push_back(2);
    EXPECT_EQ(vec.size(),2);
    EXPECT_EQ(vec[1],2);
}

TEST_F(VectorTestFixture, vectorPopBackTest) {
   vec.push_back(1);
   vec.push_back(2);

   EXPECT_EQ(vec.size(),2);
   vec.pop_back();
   EXPECT_EQ(vec.size(),1);
   vec.pop_back(); 
   EXPECT_EQ(vec.size(),0);
}

TEST_F(VectorTestFixture, vectorCapacityTest) {
    EXPECT_EQ(vec.capacity(),1);

    vec.push_back(1);
    EXPECT_EQ(vec.capacity(),1);

    vec.push_back(2);
    EXPECT_EQ(vec.capacity(),2);

    vec.push_back(3);
    EXPECT_EQ(vec.capacity(),4);
}

TEST_F(VectorTestFixture, vectorReservedTest) {
    vec.push_back(1);
    EXPECT_EQ(vec.capacity(),1);

    vec.reserve(10);
    EXPECT_EQ(vec.capacity(),10);

    vec.reserve(5);
    EXPECT_EQ(vec.capacity(),10);
}

TEST_F(VectorTestFixture, vectorEmptyTest) {
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(),3);
    
    vec.empty();
    EXPECT_EQ(vec.size(),0);

    vec.push_back(1);
    EXPECT_EQ(vec.size(),1);
    vec.empty();
    EXPECT_EQ(vec.size(),0);
}

TEST_F(VectorTestFixture, vectorAtTest) {
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.at(1),2);
    EXPECT_EQ(vec.at(0),1);
    EXPECT_EQ(vec.at(2),3);
}

TEST_F(VectorTestFixture, vectorFrontBackTest) {
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.front(),1);
    EXPECT_EQ(vec.back(),3);
}

TEST_F(VectorTestFixture, vectorShrintToFitTest) {
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    EXPECT_EQ(vec.capacity(), 4);
    vec.push_back(5);
    vec.shrink_to_fit();
    EXPECT_EQ(vec.capacity(), 5);
}
