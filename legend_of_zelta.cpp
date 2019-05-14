#include <ncurses.h>

int main() {

  // Initialize NCurses
  initscr();
  clear();

  // Print a string on screen
  printw("Hello world!\nPress any key to exit!");
  
  // Wait until the user presses a key
  getch();

  // Clear NCurses data structures
  endwin();

}
