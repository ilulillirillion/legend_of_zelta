#ifndef SPACE_H
#define SPACE_H


class Space {
  // Represents the position of the character on the map
  int _row, _column;
  // ASCII character representing the space on screen
  char _symbol;
public:
  // Constructor
  Space(char symbol, int row, int column);

  // Get the space's ASCII character
  char symbol();
  // Get the space's row(y) position
  int row();
  // Get the space's column(x) position
  int column();
};


#endif
