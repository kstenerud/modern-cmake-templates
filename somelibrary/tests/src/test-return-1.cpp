#include <gtest/gtest.h>
#include <somelibrary/somelibrary.h>

TEST(return_1, ReturnsOne)
{
    int expected = 1;
    int actual = return_1();
    ASSERT_EQ(expected, actual);
}
