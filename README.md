---

A simple C++ game built for fun and learning.

---

Compiling:
  cmake: cmake . && make
  clang: ``clang++ -std=c++11 -stdlib=libc++ -Weverything -lncurses src/hello_world.cpp -o legend_of_zelta`
  g++: `g++ -std=c++11 -lncurses src/hello_world.cpp -o legend_of_zelta`

---

Resources I've learned from:
  - https://cmake.org/pipermail/cmake/2016-May/063400.html

---

# Build 2
## Add basic spdlog test

I went with spdlog for logging because it seemed to be the most widely recommended library.

I initially had a great deal of trouble compiling it with CMake initially due to a mistake, but otherwise it seems very straightforward.

Also re-organize some of the code, put hello world in it's own directory with it's own cmake lists.

---

# Build 1
## Add a CMakeLists file

Added a CMakeLists.txt file outlining the following:

`project: legend of zelta`
Specified project name.

`cmake_minimum_required( VERSION 1.0 )`
Specifies a minimum cmake version for compiling the application. In this case, 1 is arbitrary other than seeming to successfully compile the hello world file.

`find_package( Curses REQUIRED )`
`include_directories(${CURSES_INCLUDE_DIR})`
Locate and include the Curses library, used for basic graphics.

`add_executable( legend_of_zelta ./src/hello_world.cpp )`
Include all current source files.

`target_link_libraries( legend_of_zelta ${CURSES_LIBRARIES} )`
Explicitly link any external libraries (in this case, only Curses).

---

# Build 0
## Say hello world


Initially compiled hello world and got:
```
src/hello_world.cpp:19:2: warning: extra ';' outside of a function is incompatible with C++98
      [-Wc++98-compat-pedantic]
};
```
Turns out c++ does not want semicolons ending functions so I removed the trailing semicolon and the error was gone. Compiling with either of the following worked:
`clang++ -std=c++11 -stdlib=libc++ -Weverything -lncurses src/hello_world.cpp -o legend_of_zelta`
`g++ -std=c++11 -lncurses src/hello_world.cpp -o legend_of_zelta`

The code currently prints "Hello world!" and exits on keypress.

---
