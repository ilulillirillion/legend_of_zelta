#include <ncurses.h>
#include "character.h"

#ifndef FRAME_H
#define FRAME_H

class Frame {
  // Frame dimensions
  int _height, _width;
  // Frame position
  int _row, _col;
  // Boolean - False for a window and True for a subwindow (viewport)
  bool _has_super;
  // Pointer to an NCurses window
  WINDOW *_w;
  // Pointer to an NCurses window -- null for a parent window, should point
  // to parent window for subwindows
  WINDOW *_super;
public:
  // Get the window
  WINDOW *win();
  // Get the parent window
  WINDOW *super();
  // Initialize a main window (no parent)
  Frame(int nr_rows, int nr_cols, int row_0, int col_0);
  // Initialize a subwindow (viewport) with a parent window
  Frame(Frame &sw, int nr_rows, int nr_cols, int row_0, int col_0);
  ~Frame();
  // Get window type to determine. If true, subwindow, else parent window
  bool has_super();
  // Get the height of the window
  int height();
  // Get the width of the window
  int width();
  // Get the row (y) position of the window
  int row();
  // Get the column(x) position of the window
  int col();
  
  void fill_window();

  // Refresh the window
  void refresh();

  // Move window to a new position (r, c)
  void move(int r, int c);

  // Add a character to the window
  void add(Character &x);

  void erase(Character &x);

  void add(Character &x, int row_0, int col_0);
  
  void center(Character &x);

  // Generate a game map using a Perlin noise function
  void gen_perlin(const unsigned int &seed);
  // Check if the target position is free
  bool target_position(int row_0, int col_0);

};

#endif
