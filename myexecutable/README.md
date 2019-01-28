Modern CMake Executable Template
================================

This is the minimum recommended executable build using CMake.

It covers:

 * Creating a project
 * Creating a target
 * Adding source files to the target
 * Linking to an external library
 * Building the target
 * Installing to the host system
 * Exporting the executable or source files

To build:

    mkdir build
    cd build
    cmake ..
    make

To run:

    ./myexecutable
