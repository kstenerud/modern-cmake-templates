# In this cmake file:
#  * The project is called "MyExecutable"
#  * The implementation language is C
#  * The build target is an executable file
#  * Target is "myexecutable_target", and the executable file name is "myexecutable" (on UNIX)


cmake_minimum_required(VERSION 3.5)

# Set policy to highest version, up to 3.13
if(${CMAKE_VERSION} VERSION_LESS 3.13)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.13)
endif()



#################
# Configuration #
#################

# Variables so we don't repeat ourselves
set(LOCAL_PROJECT_VERSION     "1.5.0")
set(LOCAL_PROJECT_VENDOR      "Myself")
set(LOCAL_PROJECT_NAMESPACE   "MyNamespace")
set(LOCAL_PROJECT_NAME        "MyExecutable")
set(LOCAL_PROJECT_OUTPUT_NAME "myexecutable")
set(LOCAL_PROJECT_DESCRIPTION "This is a description")

project(${LOCAL_PROJECT_NAME}
        VERSION ${LOCAL_PROJECT_VERSION}
        DESCRIPTION ${LOCAL_PROJECT_DESCRIPTION}
        LANGUAGES C)

add_executable(myexecutable_target
    src/main.c
)

# Also make it accessible via namespace
add_executable(${LOCAL_PROJECT_NAMESPACE}::${LOCAL_PROJECT_NAME} ALIAS myexecutable_target)



################
# Dependencies #
################

# Turn off testing in somelibrary.
# This is defined and checked inside somelibrary/CMakeFiles.txt
option(PACKAGE_TESTS "Build the tests" OFF)

# Normally you'd use find_package
# find_package(SomeLibrary 1.0 REQUIRED)

# In this case, we use a "subdir" and set the build dir to "somelibrary"
add_subdirectory(../somelibrary somelibrary)

target_link_libraries(myexecutable_target MyNamespace::SomeLibrary)



############
# Building #
############

# Change the output name
set_target_properties(myexecutable_target PROPERTIES
    OUTPUT_NAME ${LOCAL_PROJECT_OUTPUT_NAME}
)

# Where to find the header files
target_include_directories(myexecutable_target
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_BINARY_DIR}/gen-private-include
)

# Generate a private header "version.h" defining PROJECT_VERSION
configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/gen-private-include/version.h"
)

# Turn on warnings
target_compile_options(myexecutable_target PRIVATE $<$<CXX_COMPILER_ID:GNU>:
    -Wall
    -Wextra
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wrestrict
    -Wnull-dereference
    -Wjump-misses-init
    -Wdouble-promotion
    -Wshadow
    -fstrict-aliasing
    -Wformat=2
    # Only turn pedantic on temporarily
    # -pedantic
>)
target_compile_options(myexecutable_target PRIVATE $<$<CXX_COMPILER_ID:MSVC>:
    /W4
    /w44265
    /w44061
    /w44062
>)



#############
# Exporting #
#############

# Write a version file so that CMake's find_package() can check for a specific
# version of this package.
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${LOCAL_PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

include(GNUInstallDirs)
install(TARGETS myexecutable_target EXPORT ${LOCAL_PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

export(TARGETS myexecutable_target NAMESPACE ${LOCAL_PROJECT_NAMESPACE}:: FILE ${LOCAL_PROJECT_NAME}Targets.cmake)
export(PACKAGE ${LOCAL_PROJECT_NAME})

# Packaging
set(CPACK_PACKAGE_VENDOR ${LOCAL_PROJECT_VENDOR})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${LOCAL_PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENCE.md")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

# Source package generator
set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")
set(CPACK_SOURCE_IGNORE_FILES
    /.git*
    /dist
    /.*build.*
    /\\\\.DS_Store
)
