# Project name
project( legend_of_zelta )

# Minimum version of CMAKE required to build the project
cmake_minimum_required( VERSION 1.0 )

# Locate and include NCurses library
find_package( Curses REQUIRED )
include_directories(${CURSES_INCLUDE_DIR})

# Source files
add_executable( legend_of_zelta ./src/hello_world.cpp )

# Link external libraries (Ncurses)
target_link_libraries( legend_of_zelta ${CURSES_LIBRARIES} )
