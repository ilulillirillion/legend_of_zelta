---

A simple C++ game built for fun and learning.

At the time of this writing this project as a single contributor and, while efforts are made to keep the code organized and understandable, this repository is not guaranteed to always be in any particular state. In addition, this project is in an incredibly early stage right now, with very little in the way of planning or documentation.

That aside, it is my intention to work on this project for a long time and ultimately find find useful collaboration from elements in the community as one-off additions or short/long term collaboration. Please feel free to reach out to me here or at zolvaring@gmail.com if interested or with any other questions or concerns.

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

## Build 9
### Cleanup database connector CMakeLists, add README

Cleanup commented CMakeLists code and add a readme file for the database connector module.
Minor fixes to the project journal.

---

## Build 8
### Add a database connector module

Was finally able to take what I've learned from compiling and the tutorial file and build a simple module on top of mysql-connector-c++ for connecting to a local DB and running a query. The code is very messy for the CMakeLists file, I intend to clean it on the next commit, in case the commented code is useful. I'm not completely sure I've gotten the parts I have correct.

One concern of mine is licensing for the mysql-connector-c++ library. I've considered rewriting it and think I could make significant enough modifications in my own style to differentiate it but I'm not sure, and that may be too much work or beyond me anyway. The documentation I could find mentions a commercial distribution but I'm not able to find any more information about it. If anyone sees this and has a recommendation please let me know. For now since the code is completely open source I should satisfy requirements, I just want to keep my options open as someone new to licensing.

---

## Build 7
### Journal update: Compiling mysql libraries

Work has continued on this project over the last couple of days, but I've been stuck trying to figure how to compile any of the available mysql libraries on macos. I initially tried mysqlapi++, but I was ultimately never able to get any of the examples I could find to compile. What is also difficult is that I do not have the best understanding of the compiler tools I am using, or how C wants to link things, at this point, which makes it hard to tell differentiate user errors from actual library compatibility problems, especially when encountering older documentation or libraries. Also, a lot of the community resouces I can find online pertain to specific IDEs, usually Visual Studio, from which I can gain very little of use. I am experimenting somewhat with switching to an IDE but am still very reluctant to do so.

I was eventually able to compile what I think will be a servicable build of the mysqlcppconn library by copying the filed from the official tarball into the project and exporting a `DYLD_LIBRARY_PATH` variable to link the dynamic libraries provided in the tarball. I think how this should work is that I should be able to install with brew and have the compiler tools automatically find the libraries in path and work with them. Unfortunately, no matter what I try, I can't seem to make this happen. I don't seem to be able to get the compiler tools to recognize path changes without also changing sysroot which then seems to bring other problems, even when I'm setting it to what I think it's currently using. When I can get the compiler to actually point to the libraries installed by brew, the compiler still seems to ignore them, and I probably don't have the experience yet to catch what I am doing wrong. I think there is some combination of quirks between brew / Apple clang / my inexperience at the heart of the problem, so for right now I'm going to keep learning with the solution I have managed to put together, and hope to import these libraries in a better way later.

This bulid is simply to put this update out, as it was never my intention to go multiple days in between commits, although I am hesitant to commit without a working addition. In cases like this, I will try to put out an update containing at least a new build journal, so it is clear the projec thas not gone dark.

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
