#include <gtest/gtest.h>
#include <anotherlibrary/anotherlibrary.h>

TEST(version, ReturnsNonNull)
{
    const char* null_value = NULL;
    const char* result = anotherlibrary_version();
    ASSERT_NE(null_value, result);
}
