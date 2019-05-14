#include <ncurses.h>


class Screen {
  int _height, _width;
  public:
    // Initializes NCurses library
    Screen();
    // Clear NCurses
    ~Screen();

    // Print a message on the screen
    void add(const char *message);

    // Get screen height and width
    int height();
    int width();
};


class Character {
  int _row, _col;
  char _symbol;
  public:
    // Create a character
    Character(char symbol, int row_0, int col_0);
    // Change the character position
    void pos(int row_0, int col_0);
    // Get character's row (y) position
    int row();
    // Get characters col (x) position
    int col();
    // Get the symbol of the character
    char symbol();
};


class Frame {
  // Frame dimensions
  int _height, _width;
  // Frame position
  int _row, _col;
  // Boolean - FALSE for a window and TRUE for a subwindow (viewport)
  bool _has_super;
  // Pointer to an NCurses window
  WINDOW *_w;
  WINDOW *_super;
  public:
    // Initialize a main window (no parent)
    Frame(int nr_rows, int nr_cols, int row_0, int col_0);
    // Initialize a subwindow (viewport) with a parent window
    Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0);
    ~Frame();

    int height();
    int width();
    int row();
    int col();

    void fill_window();

    void add(Character &x, int row_0, int col_0);

    void center(Character &x);

    void refresh();
};


void erase(int y, int x) {
  mvaddch(y, x, ' ');
}


//void game_loop(char main_char, int row, int col, int user_input) {
void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int user_input) {

  // Check if the user wishes to quit
  if(user_input == 'q' || user_input == 'Q') return;
  
  // Print the main character on screen
  //mvaddch(row, col, main_char);
  //refresh();

  // Show the main character on screen
  game_map.add(main_char, main_char.row(), main_char.col());
  viewport.center(main_char);
  viewport.refresh();
  
  while(TRUE) {
    user_input = getch();
    printw("User pressed %d or %c", user_input, user_input);
    
    // Up
    if(user_input == KEY_UP || user_input == 'w' || user_input == 'W') {
      //erase(row, col);
      //row = row - 1;
      //mvaddch(row, col, main_char);
      //refresh();
      game_map.add(main_char, main_char.row() - 1, main_char.col());
      viewport.center(main_char);
      viewport.refresh();
    }
    // Right
    else if(user_input == KEY_RIGHT || user_input == 'd' || user_input == 'D') {
      //erase(row, col);
      //col = col + 1;
      //mvaddch(row, col, main_char);
      //refresh();
      game_map.add(main_char, main_char.row(), main_char.col() + 1);
      viewport.center(main_char);
      viewport.refresh();
    }
    // Down
    else if(user_input == KEY_DOWN || user_input == 's' || user_input == 'S') {
      //erase(row, col);
      //row = row + 1;
      //mvaddch(row, col, main_char);
      //refresh();
      game_map.add(main_char, main_char.row() + 1, main_char.col());
      viewport.center(main_char);
      viewport.refresh();
    }
    // Left
    else if(user_input == KEY_LEFT || user_input == 'a' || user_input == 'A') {
      //erase(row, col);
      //col = col - 1;
      //mvaddch(row, col, main_char);
      //refresh();
      game_map.add(main_char, main_char.row(), main_char.col() - 1);
      viewport.center(main_char);
      viewport.refresh();
    }
    else if(user_input == 'q' || user_input == 'Q') {
      break;
    }
  }
}


int main() {

  // Initialize NCurses
  //initscr();
  //clear();
  //noecho();
  //cbreak();
  //keypad(stdscr, TRUE);
  //curs_set(0);
  Screen scr;


  // Define the main character initial position and symbol
  //int row = 10, col = 10;
  //char main_char = '@';

  // Print a welcome message
  printw("Welcome to the Legend of Zelta!\nPress any key to start.\nPress \"q\" or \"Q\" to quit.");

  // Wait until the user presses a key
  int user_input = getch();

  // Create an NCurses window to store the game map. This will be twice the
  // size of the screen and it will be positioned at (0,0)
  Frame game_map(2*scr.height(), scr.width(), 0, 0);

  // Create an NCurses subwindow of the game map. This will have the size of
  // the user screen and it will be initially positioned at (0,0)
  Frame viewport(game_map, scr.height(), scr.width(), 0, 0);

  // Initialize the main character
  Character main_char('@', game_map.height()/2, game_map.width()/2);

  // Fill the game map with numbers
  game_map.fill_window();

  // Start the game loop
  game_loop(game_map, viewport, main_char, user_input);

  return 0;
}
