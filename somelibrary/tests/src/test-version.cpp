#include <gtest/gtest.h>
#include <somelibrary/somelibrary.h>

TEST(version, ReturnsNonNull)
{
    const char* null_value = NULL;
    const char* result = somelibrary_version();
    ASSERT_NE(null_value, result);
}
