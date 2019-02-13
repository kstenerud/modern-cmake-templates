#include <gtest/gtest.h>
#include <anotherlibrary/anotherlibrary.h>

TEST(anotherlibrary, Returns100)
{
    int expected = 100;
    int actual = return_100();
    ASSERT_EQ(expected, actual);
}
