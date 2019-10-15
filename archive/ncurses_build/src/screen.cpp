#include "screen.h"


// Initialize a new screen
Screen::Screen() {
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  // Get screen dimensions of stdscr, assigning maxy to _height and maxx to
  // _width
  getmaxyx(stdscr, _height, _width);
}


// Define a deconstructor
Screen::~Screen() {
  // Calling endwin should cleanly terminate NCurses
  endwin();
}


// Print to the screen
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
