#include "space.h"


// Constructor
Space::Space(char symbol, int row, int column) {
  _symbol = symbol;
  _row = row;
  _column = column;
}


// Get an ASCII character to represent the space on screen
int Space::symbol() {
  return _symbol;
}


// Get the row(y) position of the space
int Space::row() {
  return _row;
}


// Get the column(x) position of the space
int Space::column() {
  return _column;
}
