/*
 * Simple logger so we can get a view into what the code is doing.
 * All log entries will include the source file name, line number, and
 * function name.
 */

#include <stdio.h>
#include <string.h>

static inline const char* logger__last_path_entry(const char* path)
{
    const char* lastFile = strrchr(path, '/');
    return lastFile == 0 ? path : lastFile + 1;
}

#define LOG(MESSAGE) \
    printf("LOG MESSAGE [%s:%d %s()]: %s\n", logger__last_path_entry(__FILE__), \
        __LINE__, __PRETTY_FUNCTION__, MESSAGE);
