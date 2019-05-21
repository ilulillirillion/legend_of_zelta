# Building
Will generate an executable file `legend_of_zelta` in project directory. Regardless of how it is built, simply execute the file to launch the game. Currently the game must be launched from a terminal or terminal emulator (there are plans to bundle a terminal emulator in the future).

## CMake (Recommended)
1. `cd` into the project directory
2. `cmake .`
3. `make`

## Clang
1. `cd` into the project directory
2. `clang++ -std=c++11 -stdlib=libc++ -Weverything -lncurses src/game.cpp src/screen.cpp src/frame.cpp src/perlin_noise.cpp src/character.cpp  -o legend_of_zelta`

## g++
1. `cd` into project directory
2. `g++ -std=c++11 -lncurses src/game.cpp src/screen.cpp src/frame.cpp src/perlin_noise.cpp src/character.cpp -o legend_of_zelta`
