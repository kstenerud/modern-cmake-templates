#include <somelibrary/somelibrary.h>
#include "version.h"
#include "logger.h"

const char* somelibrary_version()
{
    return PROJECT_VERSION;
}

int return_1()
{
    LOG("Returning 1");
    return 1;
}
