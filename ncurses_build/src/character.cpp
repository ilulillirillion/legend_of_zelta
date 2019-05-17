#include "character.h"


// Instantiate
Character::Character(char symbol, int row, int column) {
  _symbol = symbol;
  _row = row;
  _column = column;
}


// Set the position of the character to match row and column
void Character::set_position(int row, int column) {
  _row = row;
  _column = column;
}


// Get the character's row(y) position
int Character::row() {
  return _row;
}


// Get the character's column (x) position
int Character::column() {
  return _column;
}


// Get the symbol of the character
char Character::symbol() {
  return _symbol;
}
