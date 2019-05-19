#include <ncurses.h>
#include "character.h"

#ifndef FRAME_H
#define FRAME_H


class Frame {
  // Frame dimensions
  int _height, _width;
  // Frame position
  int _row, _column;
  // Whether the frame has a parent
  bool _has_super;
  // Give the frame an NCurses window component
  WINDOW *_w;
  // Give the frame an NCurses parent window (should be set to NULL for parent/
  // root windows
  WINDOW *_super;
public:
  // Get the window
  WINDOW *win();
  // Get the parent window
  WINDOW *super();
  // Initialize a parentless/root window
  Frame(int rows, int columns, int start_row, int start_column);
  // Initialize a subwindow (with a parent)
  Frame(Frame &parent_window, int rows, int columns, int start_row, int start_column);
  // Deconstruct/clear the frame object
  ~Frame();
  // Check if the window has a super/parent
  bool has_super();
  // Get the height of the window
  int height();
  // Get the width of the window
  int width();
  // Get the row (y) position of the window
  int row();
  // Get the column (x) position of the window
  int column();

  // Fill the window with numbers by quadrant (for testing)
  void fill_window();

  // Refresh the window
  void refresh();

  // Move the window to a new position(row, column)
  void move(int row, int column);

  // Add a character to the window
  void add(Character &x);

  // Add a character to the window at a given position (overload)
  void add(Character &x, int row, int column);

  // Erase a character from a given position
  void erase(Character &x);

  // Center the camera around a given character
  void center(Character &x);

  // Generate a game map using a Perlin Noise function
  void generate_perlin_environment(const unsigned int &seed);
  
  // Check if a given position is moveable
  bool is_moveable(int row, int column);

};


#endif
