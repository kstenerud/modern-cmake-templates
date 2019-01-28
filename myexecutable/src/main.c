#include "version.h"
#include <somelibrary/somelibrary.h>
#include <stdio.h>

int main(void)
{
    printf("Executable version: %s\n", PROJECT_VERSION);
    printf("Somelibrary version: %s\n", somelibrary_version());
    printf("return_1: %d\n", return_1());
    return 0;
}
