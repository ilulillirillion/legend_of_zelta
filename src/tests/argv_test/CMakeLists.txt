# Project name.
project( argv_test )

# Minimum version of CMAKE required to build the project. The absolute lowest
# version has not actually been found through testing.
cmake_minimum_required( VERSION 1.0 )

# Source files.
add_executable( argv_test ./argv_test.cpp )
