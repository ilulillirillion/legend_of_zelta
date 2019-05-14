#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
  int _row, col;
  char _symbol;
  public:
    // Create a character
    Character(char symbol, int row_0, int col_0);
    // Change the character position
    void pos(int row_0, int col_0);
    // Get characters row(y) position
    int row();
    // Get characters column (x) position
    int col();
    // Get the symbol of the character
    char symbol();
};

#endif    
