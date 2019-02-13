Modern CMake Library Template
=============================

This is essentially the same library as "somelibrary", except that Google test suite is downloaded on demand rather than included as a git submodule.

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
