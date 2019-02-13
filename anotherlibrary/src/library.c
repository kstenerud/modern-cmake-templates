#include <anotherlibrary/anotherlibrary.h>
#include "version.h"
#include "logger.h"

const char* anotherlibrary_version()
{
    return PROJECT_VERSION;
}

int return_100()
{
    LOG("Returning 100");
    return 100;
}
