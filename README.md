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
  - https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/

---

## Build 6
### Create main_log module from test

Used the spdlog test to create an spdlog module for use in the actual app. The module can optionally take "test" as a parameter which will execute the test logging found in the original.

Learned that I don't have to, and probably shouldn't, use the `Weverything` flag when compiling with clang. Several tutorials that I have seen show the `Weverything` flag but it generates so many warnings that I can't address and suspect I don't need to, regarding compatibility that I am probably not trying to achieve.

I also learned that, in C, I have to declare functions above where they are first referenced in their respective files.

---

## Build 5
### Import simple argv demo from GeeksforGeeks

Importing https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/ to use as a simple standalone script for testing and learning, so I can understand how to incorporate my own
 arguments patterns elsewhere.

---

## Build 4
### Cleanup logger and add test code

---

## Build 3
### Add multi-sink multi-out spdlogging

Get a working instance of a multi-sink logger. Logs to stdout with color and logs to a log
file. Log levels and patterns can be set independently. Took lots of attempts so will have
 to come back and clean up committed commented code.

---

## Build 2
### Add basic spdlog test

I went with spdlog for logging because it seemed to be the most widely recommended library.

I initially had a great deal of trouble compiling it with CMake initially due to a mistake, but otherwise it seems very straightforward.

Also re-organize some of the code, put hello world in it's own directory with it's own cmake lists.

---

## Build 1
### Add a CMakeLists file

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

## Build 0
### Say hello world


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
