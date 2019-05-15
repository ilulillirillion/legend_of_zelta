# Legend of Zelta

A simple Roguelike built with C++ and NCurses.

For entertainment purposes only, all rights reserved. 

# Building

## g++
`g++ -std=c++11 character.cpp frame.cpp screen.cpp perlin_noise.cpp  game.cpp -lncurses -o game`

## clang
`clang++ -std=c++11 -stdlib=libc++ -Weverything character.cpp frame.cpp screen.cpp perlin_noise.cpp game.cpp -lncurses -o game`
