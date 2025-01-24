#include <gtest/gtest.h>

bool isEven(int n){ 
    return n % 2 == 0;
}
TEST(isEven, test1){
    ASSERT_TRUE(isEven(2));
    ASSERT_FALSE(isEven(3));
    ASSERT_TRUE(isEven(4));
}

TEST(isEven, test2){
    ASSERT_TRUE(isEven(2));
    ASSERT_FALSE(isEven(3));
    ASSERT_TRUE(isEven(4));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}