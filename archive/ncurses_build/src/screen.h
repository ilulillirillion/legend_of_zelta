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
  
  // Add character/s to the screen
  void add(const char *message);

};


#endif
