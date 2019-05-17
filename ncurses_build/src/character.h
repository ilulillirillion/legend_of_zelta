#ifndef CHARACTER_H
#define CHARACTER_H


class Character {
  // Represents the position of the character on the map
  int _row, _column;
  // What symbol to use to draw the character
  char _symbol;
public:
  // Constructor
  Character(char symbol, int row, int col);

  // Get character's current row (y) position
  int row();
  // Get character's current row (x) position
  int column();
  // Get character's representative symbol
  char symbol();

  // Set character position
  void set_position(int row, int col);
};


#endif
