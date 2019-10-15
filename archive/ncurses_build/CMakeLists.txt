# Minimum version of CMAKE required to build the project
cmake_minimum_required( VERSION 1.0 )

# Required to allow list initialization (used for Perlin Noise permutation
# vector declaration)
set (CMAKE_CXX_STANDARD 11)

# Project name
project( legend_of_zelta )

# Locate and include NCurses libraries
find_package( Curses REQUIRED )
include_directories(${CURSES_INCLUDE_DIR})

# Source files
add_executable( legend_of_zelta ./src/game.cpp ./src/frame.cpp ./src/screen.cpp ./src/perlin_noise.cpp ./src/character.cpp )

# Link external libraries (NCurses)
target_link_libraries( legend_of_zelta ${CURSES_LIBRARIES} )
