#include <ncurses.h>
#include <cmath>

#include "screen.h"
#include "frame.h"
#include "character.h"

void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int user_input, Character &monster) {
  // Check if user wishes to quit
  if(user_input == 'q' || user_input == 'Q') return;

  // Add the monster to the game map
  game_map.add(monster);

  // Show the main character on screen
  game_map.add(main_char);
  viewport.center(main_char);
  viewport.refresh();

  while(TRUE) {
    user_input = getch();
    
    // Upward movement
    if(user_input == KEY_UP) {
      game_map.add(main_char, main_char.row() - 1, main_char.col());
      viewport.center(main_char);
      viewport.refresh();
    }

    // Right movement
    else if(user_input == KEY_RIGHT) {
      game_map.add(main_char, main_char.row(), main_char.col() + 1);
      viewport.center(main_char);
      viewport.refresh();
    }

    // Downward movement
    else if(user_input == KEY_DOWN) {
      game_map.add(main_char, main_char.row() + 1, main_char.col());
      viewport.center(main_char);
      viewport.refresh();
    }

    // Left movement
    else if(user_input == KEY_LEFT) {
      game_map.add(main_char, main_char.row(), main_char.col() - 1);
      viewport.center(main_char);
      viewport.refresh();
    }
    else if(user_input == 'q' || user_input == 'Q') {
      break;
    }

    // NPC movements
    int pos = -1, score = game_map.height()*game_map.height() + game_map.width()*game_map.width(), dist = -1;
    // Try to move left
    if (game_map.target_position(monster.row(), monster.col() - 1)) {
      dist = std::pow(main_char.row() - monster.row(),2) + std::pow(main_char.col() - (monster.col() - 1),2);
      if (score > dist) {
        score = dist;
        pos = 0;
      }
    }
    // Try to move right
    if (game_map.target_position(monster.row(), monster.col() + 1)) {
      dist = std::pow(main_char.row() - monster.row(),2) + std::pow(main_char.col() - (monster.col() + 1),2);
      if (score > dist) {
        score = dist;
        pos = 1; 
      }
    }
    // Try to move up
    if (game_map.target_position(monster.row() - 1, monster.col())) {
      dist = std::pow(main_char.row() - (monster.row() - 1),2) + std::pow(main_char.col() - monster.col(),2);
      if(score > dist) {
        score = dist;
        pos = 2;
      }
    }
    // Try to move down
    if (game_map.target_position(monster.row() + 1, monster.col())) {
      dist = std::pow(main_char.row() - (monster.row() + 1),2) + std::pow(main_char.col() - monster.col(),2);
      if(score > dist) {
        score = dist;
        pos = 3;
      }
    }


    switch(pos) {
      case 0:
        game_map.add(monster, monster.row(), monster.col() - 1);
        break;
      case 1:
        game_map.add(monster, monster.row(), monster.col() + 1);
        break;
      case 2:
        game_map.add(monster, monster.row() - 1, monster.col());
        break;
      case 3:
        game_map.add(monster, monster.row() + 1, monster.col());
        break;
    }
    viewport.center(main_char);
    viewport.refresh();

  }
}

// Entry function for game
int main() {

  // Initialize NCurses
  Screen scr;

  // Print a welcome message
  scr.add("Welcome to the Legend of Zelta!\nPress any key to start.\nIf you want to quit press \"q\" or \"Q\"");

  // Wait until the user presses a key
  int user_input = getch();

  // Create an NCurses window to store the game map. This should be twice the
  // size of the screen and it will be positioned at 0,0
  Frame game_map(2*scr.height(), 2*scr.width(), 0, 0);

  // Create an NCurses subwindow of the game map. This should be the size of
  // the user screen and initially positioned at 0,0
  Frame viewport(game_map, scr.height(), scr.width(), 0, 0);

  // Initialize the main character
  Character main_char('@', game_map.height()/2, game_map.width()/2);

  // Initialize a test monseter
  Character test_monster('M', main_char.row() + 7, main_char.col() + 22);

  // Fill the game map with numbers
  //game_map.fill_window();

  // Fill the game map with lakes, planes, mountains and snow
  //game_map.gen_perlin(237);
  game_map.gen_perlin(211);

  // Start the game loop
  game_loop(game_map, viewport, main_char, user_input, test_monster);

  return 0;

}
