set (CMAKE_CXX_STANDARD 11)

# Project name
project( main_log )

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# Minimum version of CMAKE required to build the project
cmake_minimum_required( VERSION 3.5 )

# Source files
add_executable( main_log ./main_log.cpp )

# Link external libraries (Ncurses)
target_link_libraries( main_log PRIVATE spdlog::spdlog )
