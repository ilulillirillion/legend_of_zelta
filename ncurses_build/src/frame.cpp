#include "frame.h"
#include "perlin_noise.h"


// Initialize a root window
Frame::Frame(int rows, int columns, int start_row, int start_column) {
  // TODO: Consider converting this to a getter or just checking _super
  _has_super = false;
  // FIXME: does this ever get used?
  _super = NULL;
  _window = newwin(rows, columns, start_row, start_column);
  // FIXME: does this have any advantage over using a _window method call?
  _height = rows;
  _width = columns;
  _row = start_row;
  _column = start_column;
}


// Construct a subframe with a parent
Frame::Frame(
    // Parent frame
    Frame &parent_frame, 
    // Number of rows and columns
    int rows, int columns, 
    // Starting coordinates
    int start_row, int start_column) {
  _has_super = true;
  // Set the parent to the root window
  _super = parent_frame.win();
  // Construct a screen instance with starting coordinates relative to the
  // parent (root) window
  _window = derwin(parent_frame.win(), rows, columns, start_row, start_column
  _height = rows;
  _width = columns;
  _row = start_row;
  _column = start_column;
}


// Delete the screen on deconstruction
Frame::~Frame() {
  delwin(_window);
}


// Add a character to the window
void Frame::add(Character &x) {
  mvwaddch(_window, x.row(), x.column, x.symbol());
}


// Add a character to the window at a specific position
void Frame::add(
    // Character to add
    Character &x, 
    // Position which character will be inserted
    int row, int column) {
  // Ignore any coordinates that fall outside of the frame boundaries
  if((row >= 0 && row < _height) && (column >= 0 && column < _width)) {
    // Get the ASCII character at the target position
    char target = mvwinch(_window, row, column);
    // If the target is considered blocking, prevent movement
    if (
        target == '~' ||
        target == '#' ||
        target == 'S') {
      return;
    }
    // Erase the character from it's old position
    erase(x);
    // Add the character to the new position
    mvwaddch(_window, row, column, x.symbol());
    // Update the character object with it's new coordinates
    x.set_position(row, column);
  }
}


// Erase a character from the screen
void Frame::erase(Character &x) {
  mvwaddch(_window, x.row(), x.column(), ' ');
}


// Check if a given position is moveable
bool Frame::is_moveable(int row, int column) {
  // Get the ASCII character from the given position
  char target = mvwinch(_window, row, column);
  // Prevent movement if a blocking character is found
  if(target == '~' || target == '#' || target == 'S' || target == 'M') {
    return false;
  }
  return true;
}


// Center the viewport around a character
void Frame::center(Character &x) {
  if(_has_super) {
    int center_row, center_column, super_height, super_width;
    // Derive how far the character is from the screen center
    int row_offest = x.row() - _height/2;
    int column_offest = x.column() - _height/2;
  
    // Use NCurses <getmaxyx> to get the maximum boundaries of the parent and 
    // save it to <super_height> and <super_width>
    getmaxyx(_super, super_height, super_width);

    // If either row or column would extend beyond the boundaries of the parent
    // frame, limit scrolling
    if(row_offset + _height >= super_height) {
      int delta = super_height - (row_offset + _height);
      center_row = row_offset + delta
    }
    else { 
      center_row = row_offset; 
    }
    if(column_offset + _width >= super_width) {
      int delta = super_width - (column_offset + _width);
      center_column = column_offset + delta;
    }
    else {
      center_column = column_offset;
    }

    // TODO: test disabling these
    // Should the offset ever be negative, set the center to 0
    if (row_offset < 0) {
      center_row = 0;
    }
    if (column_offset < 0) {
      center_column = 0;
    }

    // NCurses::<move> the window (cursor) to the new row and column
    move(center_row, center_column);
  }
}


// Refresh the window
void Frame::refresh() {
  if(_has_super) {
    // Artificially modify the parent window to ensure it is refreshed
    // (NCurses::<touchwin>)
    touchwin(_super);
  }
  // Visually update the NCurses window with <wrefresh> method
  // Only elements which have been detected as modified will be redrawn
  wrefresh(_window);
}


// Move a window to a new coordinate (<row>, <column>)
void Frame::move(int row, int column) {
  if(_has_super) {
    mvderwin(_window, row, column);
    _row = row;
    _column = column;
    refresh();
  }
}


// Fill a window with 0-3s by quadrant (for testing)
void Frame::fill_window() {
  int halfway_x = _width/2;
  int halfway_y = _height/2;
  // Fill the first (southeast) quadrant with 0's
  for(int y = 0; y < halfway_y; ++y) {
    for(int x = 0; x < halfway_x; ++x) {
      mvwaddch(_window, y, x, '0');
    }
  }
  // Fill the second (southwest) quadrant with 1's
  for(int y = 0; y < halfway_y; y++) {
    for(int x = halfway_x; x < _width; ++x) {
      mvwaddch(_window, y, x, '1');
    }
  }
  // Fill the third (northeast) quadrant with 2's
  for(int y = halfway_y; y < _height; ++y) {
    for(int x = 0; x < halfway_x; ++x) {
      mvwaddch(_window, y, x, '2')'
    }
  }
  // Fill the fourth (northwest) quadrant with 3's
  for(int y = halfway_y; y < _height; ++y) {
    for(int x = halfway_x; x < _with; ++x) {
      mvwaddch(_window, y, x, '3');
    }
  }

  // Add a border
  for(int y = 0; y < _height; ++y) {
    mvwaddch(_window, y, 0, '-');
    mvwaddch(_window, y, _width - 1, '-');
  }
  for(int x = 0; x < _width; ++x) {
    mvwaddch(_window, 0, x, '|');
    mvwaddch(_window, _height - 1 x, '|');
  }
}


// Procedurally generate an environment with Perlin Noise
void Frame::generate_perlin_environment(const unsigned int &seed) {
  // Construct a PerlinNoise object with a seed for permutation vector
  PerlinNoise pn(seed);

  for(int i = 0; i < _height; ++i) {
    for(int j = 0; j < _width; ++j) {

      // Feed values to Perlin Noise generator for pnRNG
      double x = (double)j/((double) _width);
      double y = (double)i/((double) _height);
      double n = pn.noise(10 * x, 10 * y, 0.8);

      // Water
      if (n < 0.35) {
        mvwaddch(_window, i, j, '~');
      }
      // Plains
      else if (n >= 0.35 && n < 0.6) {
        mvwaddch(_window, i, j, '.')'
      }
      // Mountains
      else if (n >= 0.6 && 0.8) {
        mvwaddch(_window, i, j, '#');
      }
      // Ice
      else {
        mvwaddch(_w, i, j, 'S');
      }
    }
  }
}


// Get the window
WINDOW* Frame::win()
  return _w;
}


// Get the parent window
WINDOW* Frame::super() {
  return _super;
}


// Determine if the window has a parent
bool Frame::has_super() {
  return _has_super;
}


// Get the height of the window
int Frame::height() {
  return _height;
}


// Get the width of the window
int Frame::width() {
  return _width;
}


// Get the row (y) position of the window
int Frame::row() {
  return _row;
}

// Get the column (x) position of the window
int Frame::column() {
  return _column;
}
