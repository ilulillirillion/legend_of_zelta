#include <ncurses.h>


void erase(int y, int x) {
  mvaddch(y, x, ' ');
}


void game_loop(char main_char, int row, int col, int user_input) {

  // Check if the user wishes to quit
  if(user_input == 'q' || user_input == 'Q') return;
  
  // Print the main character on screen
  mvaddch(row, col, main_char);
  refresh();

  for(;;) {
    user_input = getch();
    
    // W or Up
    if(user_input == KEY_UP) {
      erase(row, col);
      row = row - 1;
      mvaddch(row, col, main_char);
      refresh();
    }
    // Right
    else if(user_input == KEY_RIGHT) {
      erase(row, col);
      col = col + 1;
      mvaddch(row, col, main_char);
      refresh();
    }
    // Down
    else if(user_input == KEY_DOWN) {
      erase(row, col);
      row = row + 1;
      mvaddch(row, col, main_char);
      refresh();
    }
    // Left
    else if(user_input == KEY_LEFT) {
      erase(row, col);
      col = col - 1;
      mvaddch(row, col, main_char);
      refresh();
    }
    else if(user_input == 'q' || user_input == 'Q') {
      break;
    }
  }
}


int main() {

  // Initialize NCurses
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  // Define the main character initial position and symbol
  int row = 10, col = 10;
  char main_char = '@';

  // Print a welcome message
  printw("Welcome to the Legend of Zelta!\nPress any key to start.\nPress \"q\" or \"Q\" to quit.");

  // Wait until the user presses a key
  int user_input = getch();

  // Clear the screen
  clear();

  // Start the game loop
  game_loop(main_char, row, col, user_input);

  // Clear NCurses data structures
  endwin();

  return 0;
}

