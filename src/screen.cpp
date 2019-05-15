#include "screen.h"

// Initialize the NCurses library
Screen::Screen() {
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);
  // Get screen dimensions
  getmaxyx(stdscr, _height, _width);
}


// Clear NCurses
Screen::~Screen() {
  endwin();
}


// Print a message on the screen
void Screen::add(const char *message) {
  printw(message);
}


// Get the screen height
int Screen::height() {
  return _height;
}


// Get the screen width
int Screen::width() {
  return _width;
}
