set (CMAKE_CXX_STANDARD 11)

# Project name
project( spdlog_test )

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# Minimum version of CMAKE required to build the project
cmake_minimum_required( VERSION 3.5 )

# Source files
add_executable( spdlog_test ./spdlog_test.cpp )

# Link external libraries (Ncurses)
target_link_libraries( spdlog_test PRIVATE spdlog::spdlog )

# Make the log directory to use.
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/logs")
