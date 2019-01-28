Modern CMake Library Template
=============================

This is the minimum recommended library build using CMake.

It covers:

 * Creating a project
 * Creating a target
 * Adding source files to the target
 * Building the target
 * Unit tests
 * Installing to the host system
 * Exporting the library or source files

To build:

    mkdir build
    cd build
    cmake ..
    make

To run unit tests:

    make test

You can also run the tests manually:

    ./tests/MyTest
