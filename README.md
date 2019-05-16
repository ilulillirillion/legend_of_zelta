# Legend of Zelta

A simple Roguelike built with C++ and NCurses.

For entertainment purposes only, all rights reserved. 

# Building

## g++
1. `cd` into the `src` directory
2. `g++ -std=c++11 character.cpp frame.cpp screen.cpp perlin_noise.cpp  game.cpp -lncurses -o game`
3. Execute game (`./game`)

## clang
1. `cd` into the `src` directory
2. `clang++ -std=c++11 -stdlib=libc++ -Weverything character.cpp frame.cpp screen.cpp perlin_noise.cpp game.cpp -lncurses -o game`
3. Execute game (`./game`)

