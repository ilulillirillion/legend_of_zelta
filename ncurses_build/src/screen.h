#include <ncurses.h>


#ifndef SCREEN_H
#define SCREEN_H


class Screen {
  int _height, _width;

public:

  // Construct an NCurses screen
  Screen();

  // Descontruct an NCurses screen
  ~Screen();

  // Get height
  int height();
  // Get width
  int width();
  
  // Print a message on the screen
  void print_message(const char *message);

};


#endif
